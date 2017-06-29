/***********************************************************************************\
* Created: 6/30/2017 by Ali Sepehri-Amin
* Version: 1.00
* Description: -
\***********************************************************************************/


#ifndef __ENCRYPTION_H__
#define __ENCRYPTION_H__

#include <string>
#include <iostream>

using namespace std;

class CEncryption
{
public:
	string XOR(string data, char key[]);
	int generateRandomNumber(int i);
	void EncryptPng();
	void EncryptJpg();
	void EncryptZip();
private:
	char key[10] = { 'K', 'E', 'Y','I','E','Q','W','X','R','H' };
};


#endif //__ENCRYPTION_H__
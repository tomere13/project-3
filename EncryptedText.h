#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "Text.h"
#pragma once
using namespace std;
class EncryptedText: public Text {
	Text* ptrObj;
	bool status;
	int* EncryptKey;
	int size;

public:

	EncryptedText():ptrObj(NULL),status(0),EncryptKey(NULL),size(0){}
	EncryptedText(const string,const bool);
	~EncryptedText();
	EncryptedText& operator += (int*);
	EncryptedText& operator ! ();
	EncryptedText& operator & ();
	friend ostream& operator << (ostream&, const EncryptedText&);

};


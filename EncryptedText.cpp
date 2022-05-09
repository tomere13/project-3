#include "EncryptedText.h"
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "Word.h"
#pragma once
using namespace std;

EncryptedText::EncryptedText(const string text_obj, const bool stat):status(stat),size(0),EncryptKey(NULL),ptrObj(NULL) {
	ptrObj = new Text(text_obj);
}

EncryptedText::~EncryptedText() {
	if (ptrObj) delete ptrObj;
	if (EncryptKey) delete[] EncryptKey;
}

EncryptedText& EncryptedText::operator +=(int* a) {
	int i = 0;
	if (a) {
		while (a[i] != -2) {
			size++;
			i++;
		}

		EncryptKey = new int[size];
		for (i = 0; i < size; i++) EncryptKey[i] = a[i];
	}
	return *this;
}
EncryptedText& EncryptedText:: operator ! () {
	for (int i = 0; i < size; i += 3) {
		int code = EncryptKey[i], location = EncryptKey[i + 1], parameter = EncryptKey[i + 2];
		if (location == -1) {
			switch (code) {
			case 1:
				*ptrObj << (parameter);
				break;
			case 2:
				*ptrObj >> (parameter);
				break;
			case 3:
				*ptrObj += (parameter);
				break;
			case 4:
				!*ptrObj;
				break;
			case 5:
				&*ptrObj;
				break;
			}
		}
		else {
			switch (code) {
			case 1:
				(*ptrObj)[location][0] << (parameter);
				break;
			case 2:
				(*ptrObj)[location] >> (parameter);
				break;
			case 3:
				(*ptrObj)[location] += (parameter);
				break;
			case 4:
				!ptrObj[location];
				break;
			case 5:
				&ptrObj[location];
				break;
			}
		}
	}
	status = 1;
	return *this;

}

EncryptedText& EncryptedText::operator& () {
	for (int i = size - 1; i >= 0; i -= 3) {
		int code = EncryptKey[i - 2], location = EncryptKey[i - 1], parameter = EncryptKey[i];
		if (location == -1) {
			switch (code) {
			case 1:
				*ptrObj >> parameter;
				break;
			case 2:
				*ptrObj << parameter;
				break;
			case 3:
				*ptrObj -= parameter;
				break;
			case 4:
				!*ptrObj;
				break;
			case 5:
				&*ptrObj;
				break;
			}
		}
		else {
			switch (code) {
			case 1:
				(*ptrObj)[location][0] >> parameter;
				break;
			case 2:
				(*ptrObj)[location] << parameter;
				break;
			case 3:
				(*ptrObj)[location] -= parameter;
				break;
			case 4:
				!ptrObj[location];
				break;
			case 5:
				&ptrObj[location];
				break;
			}
		}
	}
	status = 0;
	return *this;
}

ostream& operator << (ostream& out, const EncryptedText& obj) {
	if (obj.ptrObj) {
		if (obj.status == 0) {
			cout << "The decrypted text: " << *obj.ptrObj << endl;
			if (obj.EncryptKey) {
				cout << "the key: " << endl;
				for (int i = 0; i < obj.size; i += 3)
					cout << obj.EncryptKey[i] << " " << obj.EncryptKey[i + 1] << " " << obj.EncryptKey[i + 2] << endl;;
			}
			else
				cout << "the key: empty" << endl;
		}
		else if (obj.status == 1) {
			cout << "The encrypted text: " << *obj.ptrObj << endl;
			if (obj.EncryptKey) {
				cout << "the key: " << endl;
				for (int i = 0; i < obj.size; i += 3)
					cout << obj.EncryptKey[i] << " " << obj.EncryptKey[i + 1] << " " << obj.EncryptKey[i + 2] << endl;;
			}
			else
				cout << "the key: empty" << endl;
		}
		return out;
	}
}


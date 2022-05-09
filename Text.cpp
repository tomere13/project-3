#include "Text.h"
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#pragma once
using namespace std;


Text::Text(string a):sizeOfptr(1),ptrWords(NULL) {
	int i = 0,j;
	int pos;
	while (a[i] != '\0') {
		if (a[i] == ' ')sizeOfptr++;
		i++;
	}
	ptrWords = new Word*[sizeOfptr];

	string temp;

	for (j = 0; j < sizeOfptr; j++) {
		pos = a.find(" ");
		temp = a.substr(0, pos);
		ptrWords[j] = new Word(temp, temp.length() );
		a = a.substr(pos + 1);
	}

}

Text::Text(const Text& other) { 
	sizeOfptr = other.sizeOfptr;
	ptrWords = new Word*[sizeOfptr];
	for (int i = 0; i < sizeOfptr; i++)
		ptrWords[i] = new Word(*other.ptrWords[i]);
}


Text& Text::operator !() {
	for (int i = 0; i < sizeOfptr; i++) !(ptrWords[i]);
	return *this;
}

Text& Text::operator & () { 
	Word** temp = new Word * [sizeOfptr + 1];
	for (int i = 0; i < sizeOfptr; i++)
		temp[i] = ptrWords[i];
	ptrWords = new Word * [sizeOfptr + 1];
	for (int i = sizeOfptr - 1, j = 0; j < sizeOfptr; i--, j++)
		ptrWords[i] = temp[j];
	return *this;
}

Text& Text::operator << (int n) {
	for (int i = 0; i < n; i++) {
		ptrWords[sizeOfptr - 1] = ptrWords[0];
		for (int j = 0; j < sizeOfptr - 1; j++) {
			ptrWords[j] = ptrWords[j + 1];
		}
	}
	return *this;
}

Text& Text::operator >> (int m) {
	for (int i = 0; i < m; i++) {
		ptrWords[sizeOfptr - 1] = ptrWords[0];
		for (int j = sizeOfptr - 1; j > 1; j--) {
			ptrWords[j] = ptrWords[j - 1];
		}
	}
	return *this;
}

Text& Text::operator += (int n) {
	int newsize = rand() % 20;
	int value;
	char* newword = new char[newsize];
	for (int i = 0; i < newsize; i++) {

		int alpha_num = rand() % 3;
		char temp=NULL;
		switch (alpha_num) {
		case 0:
			value = rand() % 10;
			temp = value + '0';
			break;
		case 1:
			value = rand() % 26;
			temp = value + 'a';
			break;
		case 2:
			value = rand() % 26;
			temp = value + 'A';
			break;
		}
		newword[i] = temp;
	}

	Word** newptr = new Word* [sizeOfptr + 1];
	for (int i = 0; i < (sizeOfptr + 1); i++) {
		if (i != n) newptr[i] = ptrWords[i];
		else if (i == n) newptr[i] = new Word(newword,newsize);
	}

	Text::~Text();
	ptrWords = newptr;
	return *this;
}

Text& Text::operator -= (int n) {
	int j = 0;
	Word** newptr = new Word* [sizeOfptr - 1];
	for (int i = 0; i < (sizeOfptr - 1); i++) {
		if (i != n) newptr[i - j] = ptrWords[i];
		else j++;
	}
	Text::~Text();
	ptrWords = newptr;
	return *this;
}

Word& Text::operator[](int n) {
	if (n >= sizeOfptr || n < 0) {
		cout << "Error" << endl;
		exit(1);
	}
	else
		return *ptrWords[n];
}

ostream& operator<<(ostream& output, const Text& a) {
	if(a.ptrWords){
	for(int i =0; i< a.sizeOfptr;i++){
		cout << *a.ptrWords[i]<< ' '<<endl;
	}

	return output;
	}
}
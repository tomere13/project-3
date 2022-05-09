#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "Word.h"
#pragma once
using namespace std; 
class Text: public Word{
	Word** ptrWords;
	int sizeOfptr;

public:
	void set_ptr();
	Text(string);
	
	Text():ptrWords(NULL),sizeOfptr(0){}
	Text(const Text& other);
	~Text() { if(ptrWords) for (int i = 0; i < sizeOfptr; i++) delete ptrWords[i]; delete ptrWords; }
	Text& operator !();
	Text& operator &();
	Text& operator << (int);
	Text& operator >> (int);
	Text& operator += (int);
	Text& operator -= (int);
	Word& operator [](int);
	friend ostream& operator<<(ostream&, const Text&);
};


#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#pragma once
using namespace std;
class Word
{
	char* Words;
	int size;
public:
	Word():Words(NULL),size(0){}
	Word(string a,int b);
	~Word() {if(Words)delete Words;}
	char* give_word();
	void set_string(string);
	
	Word& operator ! ();
	Word& operator & ();
	Word& operator << (int);
	Word& operator >> (int);
	Word& operator += (int);
	Word& operator -= (int);
	char operator [] (int);
	friend ostream& operator<<(ostream&, const Word&);
};


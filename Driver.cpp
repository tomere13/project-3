#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "Text.h"
#include "EncryptedText.h"
#pragma once
using namespace std;
#include "Word.h"

int main() {
	/*EncryptedText etext1("The London is capital of Great Britian.", 0);
	int key1[] = { 3, -1, 4, 1, -1, 3, 1, 0, 4, 4, -1, 0, 5, -1, 0, -2 };
	cout << etext1;
	etext1 += key1;
	cout << !(etext1);
	cout << "----------------------------------------------------------" << endl;
	EncryptedText etext2("RH oLMWLM gSV yIRGRZM tIVZG LU 3eCQ GZOXZKR.", 1);
	etext2 += key1;
	cout << etext2;
	&etext2;
	cout << etext2;
	return 0;*/
	Word a("Tomer3", 5);
	&a;
	cout << a;

}
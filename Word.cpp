#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "Word.h"
using namespace std;

void Word::set_string(string a) {
		size = a.length() ;
		Words = new char[size];
		for (int i = 0; i < size; i++) {
			Words[i] = a[i];
		}
	}

char* Word::give_word() {
	return Words;
}
Word::Word(string a, int b){
	set_string(a);
}
Word& Word:: operator!() {
	for (int i = 0; i < size; i++) {
		if (Words[i] >= '0' && Words[i] <= '9') Words[i] = '9' - Words[i] + 48;
		else if (Words[i] >= 'a' && Words[i] <= 'z') {
			Words[i] = toupper(Words[i]);
			Words[i] = 'Z' - Words[i] + 65;
		}
		else if (Words[i] >= 'A' && Words[i] <= 'Z') {
			Words[i] = tolower(Words[i]);
			Words[i] = 'z' - Words[i] + 97;
		}
	}
	return *this;
}

Word& Word:: operator & () {
	char temp;
	for(int i = 0; i < size/2 ;i++) {
		temp = Words[i];
		Words[i] = Words[size - 1 - i];

}
	return *this;
}

Word& Word::operator << (int n) {
	/*for (int i = 0; i < n; i++) {
		Words[size - 1] = Words[0];
		for (int j = 0; j < size - 1; j++) {
			Words[j] = Words[j + 1];
		}
	}
	return *this;*/
	char temp = Words[0];
	for (int i = 0; i < size - 1; i++)
		Words[i] = Words[i + 1];
	Words[size - 1] = temp;
	return *this;
}
Word& Word::operator >> (int m) {
	for (int i = 0; i < m; i++) {
		Words[size - 1] = Words[0];
		for (int j = size-1; j>1 ; j--) {
			Words[j] = Words[j - 1];
		}
	}
	return *this;
}

Word& Word::operator += (int a) {
	int value;
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
	size++;
	string str_temp;
	for (int i = 0; i < size; i++) {
		if (i != a) str_temp[i] = Words[i];
		else if (i == a) str_temp[a] = temp;
	}
	set_string(str_temp);
	return *this;
}

Word& Word::operator -= (int a) {
	
	string str_temp;
	for (int i = 0; i < size - 1; i++) {
		if (i!=a) str_temp[i] = Words[i];
	}
	set_string(str_temp);
	return *this;
}

char Word::operator[](int a) {
	int n = a % size;
	return Words[n];
}

ostream& operator<<(ostream& output, const Word& a) {
	if (a.Words) {
		for (int i = 0; i < a.size; i++) cout << a.Words[i];;
		return output;
	}
}

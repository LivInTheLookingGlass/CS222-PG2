//Gabe Appleton, CS222
//This is the header file for the linked list node used in this program
#ifndef _LLNH_
#define _LLNH_

#include <string>
#include <iostream>
#include "LL.h"


using namespace std;

class LLN	{
private:
	string content;
	LLN *next;
	LLN *prev;
public:
	LLN(string s);
	LLN(LLN *p, string s);
	LLN(LLN *p, LLN *n, string s);
	~LLN();
	void sort(LLN *list[], int charNum);
	void print();
	void add(string s);
	int length();
	LLN * prepend(LLN *p);
	void append(LLN *n);
	string getContent();
	void setPrev(LLN *p);
	LLN *getPrev();
	void setNext(LLN *n);
	LLN *getNext();
};

#endif

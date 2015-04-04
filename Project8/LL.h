//Gabe Appleton, CS222
//This is the header for the linked list class used in this program
#ifndef _LLH_
#define _LLH_

#include <string>
#include <iostream>
#include "LLN.h"

using namespace std;

class LLN;
class LL	{
private:
	LLN *head;
	void replaceWithArray(LLN *array[], bool replaced, int index);
	void populate(LLN *array[], int ln, int i);
	void recursiveSort(LLN *list[], int iterations);
	void recursiveDelete(LLN *list[], int ln, int index);
public:
	LL();
	~LL();
	void print();
	void add(string s);
	void sort();
	void setHead(LLN *h);
	LLN *getHead();
};

#endif

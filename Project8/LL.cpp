//Gabe Appleton, CS222
//This is the class for the linked list used in this program
#include <string>
#include <iostream>
#include "LL.h"
#include "LLN.h"

using namespace std;

//this is the constructor
LL::LL()	{
	head = NULL;
}

//this is the destructor
LL::~LL()	{
	delete head;
}

//this prints the value of each node in the list
void LL::print()	{
	if (head)
		head->print();
}

//this adds an item to the end of the linked list
void LL::add(string s)	{
	if (!head)
		setHead(new LLN(s));
	else
		head->add(s);
}

//this calls the native sort function of the linked list nodes
void LL::sort()	{
	if (!head)
		return;
	int length = head->length()-1;
	LLN *list[27];
	populate(list,27,0);
	recursiveSort(list,length);
	recursiveDelete(list,27, 0);
	//for (int i = 0; i < 27; i++)
		//delete list[i];
	/*delete[] list;*/
}

void LL::recursiveDelete(LLN *list[], int ln, int index)	{
	if (index < ln)	{
		recursiveDelete(list,ln,index+1);
		delete list[index];
	}
}

//this allows for a recursive calling of this sort method, until it is fully in order
void LL::recursiveSort(LLN *list[], int iterations)	{
	int l = head->length();
	head->sort(list,iterations);
	replaceWithArray(list,false,26);
	populate(list,27,0);
	//head->print();
	if (iterations-1 < 0)
		return;
	recursiveSort(list,iterations-1);
}

//this populates an array of "empty" nodes to sort with
void LL::populate(LLN *array[], int ln, int i)	{
	if (i < ln)	{
		array[i] = new LLN("");
		populate(array,ln,i+1);
	}
}

//this replaces the current head with the array of sorted nodes
void LL::replaceWithArray(LLN *array[], bool replaced, int index)	{
	if (index < 0)
		return;
	if (array[index]->getContent() != "")
		if (!replaced)	{
			head = array[index];
			replaced = true;
		}
		else
			head = head->prepend(array[index]);
	replaceWithArray(array,replaced,index-1);
}

//this mutator sets the head
void LL::setHead(LLN *h)	{
	head = h;
}

//this retriever returns the head
LLN *LL::getHead()	{
	return head;
}

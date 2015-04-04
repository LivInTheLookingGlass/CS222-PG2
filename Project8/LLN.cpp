//Gabe Appleton, CS222
//This is the main file for the linked list node used in this program
#include <string>
#include <iostream>
#include "LLN.h"

using namespace std;

//These contstructors allow you to do more specific operations in one line, if needed
LLN::LLN(string s)	{
	prev = NULL;
	next = NULL;
	content = s;
}
LLN::LLN(LLN *p, string s)	{
	prev = p;
	next = NULL;
	content = s;
}
LLN::LLN(LLN *p, LLN *n, string s)	{
	prev = p;
	next = n;
	content = s;
}

//this is the destructor
LLN::~LLN()	{
	delete next;
}

//this is the native sort function of the linked list, splitting the nodes into different "columns" of the supplied array based on their character value
void LLN::sort(LLN *list[], int charNum)	{
	LLN *n = next;
	next = NULL;
	prev = NULL;
	int num = 0;
	if (n)
		n->sort(list, charNum);
	if (content.length() > charNum && content[charNum] >= 'A' && content[charNum] <= 'Z')
		num = 1 + content[charNum] - 'A';
	if (list[num]->getContent() == "")
		list[num] = this;
	else
		list[num] = list[num]->prepend(this);
}

//this recursively prints the linked list
void LLN::print()	{
	cout << content << endl;
	if (next)
		next->print();
}

//this returns the length of the linked list
int LLN::length()	{
	int i = 0;
	if (next)
		i = next->getContent().length();
	if (i < (int)content.length())
		i = content.length();
	return i;
}

//this appends an item to the linked list (different from append because you supply a string, not a node)
void LLN::add(string s)	{
	if (next)
		next->add(s);
	else	{
		next = new LLN(this,s);
	}
}

//this prepends an item to the linked list
LLN * LLN::prepend(LLN *p)	{
	if (prev)	{
		prev->setNext(p);
		p->append(this);
		p->setPrev(prev);
	}
	else	{
		prev = p;
		prev->append(this);
	}
	return p;
}

//this appends an item to the linked list (different from add because you supply a node, not a string)
void LLN::append(LLN *n)	{
	if (next)
		next->append(n);
	else	{
		next = n;
		n->setPrev(this);
	}
}

//this accessor returns the content of the node
string LLN::getContent()	{
	return content;
}

//this mutator sets the previous node
void LLN::setPrev(LLN *p)	{
	prev = p;
}

//this accessor returns the previous node
LLN *LLN::getPrev()	{
	return prev;
}

//this mutator sets the next node
void LLN::setNext(LLN *n)	{
	next = n;
}

//this accessor returns the next node
LLN *LLN::getNext()	{
	return next;
}

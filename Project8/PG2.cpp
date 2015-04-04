//Gabe Appleton, CS222
//This is the main file for the program which will sort given strings (if they only contain spaces and alphabetical characters)
#include <string>
#include <iostream>
#include "PG2.h"
#include "LL.h"

using namespace std;

LL *l;

//This is the main method, which sets up the initial conditions
int main (int argc, char* argv[])	{
	l = new LL();
	getInput();
	l->sort();
	l->print();
	system("pause");

	return 0;
}

//this method retrieves and handles all input
void getInput()	{
	cout << "command:" << endl;
	string s;
	getline(cin, s);
	allcaps(s, 0);
	cout << "Input: " << s << endl;
	if (s != "")	{
		l->add(s);
		getInput();
	}
}

//this (unneccesary) method converts all lowercase letters into uppercase ones
void allcaps (string &input, int index)	{
	if (input[index] <= 'z' && input[index] >= 'a')
		input[index] = input[index] - 'a' + 'A';
	if (index < input.length())
		allcaps(input,index+1);
}

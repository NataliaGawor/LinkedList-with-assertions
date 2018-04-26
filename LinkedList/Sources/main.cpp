
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "List.h"

#include <cassert>

using namespace std;

template<class T>
T stringToValue(string str) {
	istringstream iss(str);
	T value;
	iss >> value;
	return value;
}

void ignoreWhiteMarks(istream& in) {
	while (in.peek() == 10 || in.peek() == 32)
		in.ignore();
}


int main(int argc, char *argv[])
{
	string fileName = argv[1];

	double a2,a3;

	a2 = stringToValue<double>(argv[2]);
	a3 = stringToValue<double>(argv[3]);

	double min = a2;
	double max = a3;

	cout << "MIN: " << min << endl;
	cout << "MAX: " << max << endl;
	string value;
	char what;
	string str;
	filebuf* fb = new filebuf();
	assert(fb != NULL); //check memory allocation


	fb->open(fileName, ios::in);
	istream plik(fb);
	if (plik) //check if file open
	{
		while (!plik.eof()) {
			ignoreWhiteMarks(plik);
			what = plik.peek(); //podglądamy co jest w strumieniu
			if (isdigit(what)) {
				plik >> value;

				double d = stringToValue<double>(value);
				cout << "VALUE: " << d << endl;
				assert(d>min);
				assert(d<max);
				

				//add to list here
			}
			else {
				plik >> str;
			}
		}
		fb->close();
	}
	else{
		cout << "Error with open file";
	}

	system("pause");
	return 0;
}
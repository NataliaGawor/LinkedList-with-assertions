#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
#include "../Headres/LinkedList.h"
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
    LinkedList *linkedList = new LinkedList();
    string fileName = argv[1];
    double min = stringToValue<double>(argv[2]);
    double max = stringToValue<double>(argv[3]);

    cout<< "min: "<< min << endl;
    cout<< "max: "<< max << endl;

    string value;
    char what;
    string str;
    filebuf* fb = new filebuf();

    assert(fb != NULL); //check memory allocation

    fb->open(fileName, ios_base::in);
    assert(fb->is_open());
    istream plik(fb);
    while (!plik.eof()) {
        ignoreWhiteMarks(plik);
        what = plik.peek(); //check what is inside of stream
        if (isdigit(what)) {
            plik >> value;
            double d = stringToValue<double>(value);
            cout<< "add val: "<< d << endl;
            assert(d>min);
            assert(d<max);
            linkedList->add(d);
        }
        else {
            plik >> str;
        }
    }
    fb->close();


//    linkedList->showLeftToRight();
//    linkedList->removeList();
    system("pause");
    return 0;
}
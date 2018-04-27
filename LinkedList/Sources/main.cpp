#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
#include "../Headres/LinkedList.h"
#define NDEBUG
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

    linkedList->add(2.9);
    linkedList->add(5.9);
    linkedList->add(5.9);
    linkedList->add(1.9);
    linkedList->add(6.9);
    linkedList->add(5.9);

    linkedList->showLeftToRight();
    cout << endl;

    linkedList->add(5.2);
    linkedList->showLeftToRight();
    cout << endl;

  //  linkedList->removeList();
  //  cout<<"Lista po usunieciu  :";
  //  linkedList->showLeftToRight();
//    cout << endl<< "end"<<endl;

    string fileName = argv[1];
  //  cout << "file: " << fileName << endl;
    double a2,a3;

    a2 = stringToValue<double>(argv[2]);
    a3 = stringToValue<double>(argv[3]);

    double min = a2;
    double max = a3;

   // cout << "MIN: " << min << endl;
   // cout << "MAX: " << max << endl;

    string value;
    char what;
    string str;
    filebuf* fb = new filebuf();
    assert(fb != NULL); //check memory allocation

    fb->open(fileName, ios_base::in);
    istream plik(fb);
    if (plik) //check if file open
    {
      //  cout << "file is open" << endl;
        while (!plik.eof()) {
            ignoreWhiteMarks(plik);
            what = plik.peek(); //podglądamy co jest w strumieniu
           // cout << what << "<- what is inside"<< endl;
            if (isdigit(what)) {
                plik >> value;
                cout << value << "<- value from file"<< endl;
                double d = stringToValue<double>(value);
                cout << "VALUE: " << d << endl;
                assert(d>min);
                assert(d<max);

                // add element to list
            }
            else {
                plik >> str;
              //  cout << str << "<- sth wired"<< endl;
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
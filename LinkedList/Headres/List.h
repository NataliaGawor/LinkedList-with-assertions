//
// Created by Natalia on 26.04.2018.
//

#ifndef LINKEDLIST_LIST_H
#define LINKEDLIST_LIST_H


#include "el.h"

class List {
    int minVal;
    int maxVal;
    el *head;
    el *tail;

public:
    List(int minVal, int maxVal); //okreslenie zakresu
    el* add(int a);
    void removeList();
    void showRightToLeft();
    void showLeftToRight();

};


#endif //LINKEDLIST_LIST_H

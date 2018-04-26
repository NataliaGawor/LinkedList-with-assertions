//
// Created by Natalia on 26.04.2018.
//

#ifndef LINKEDLIST_LIST_H
#define LINKEDLIST_LIST_H

#include <iostream>
#include "el.h"

class LinkedList {
    el *head;
    el *tail;
public:
    LinkedList();
    void add(double a);
    void removeVal(double val);
    void removeList();
    void showRightToLeft();
    void showLeftToRight();

};


#endif //LINKEDLIST_LIST_H

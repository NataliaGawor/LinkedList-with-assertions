//
// Created by Natalia on 26.04.2018.
//

#define NDEBUG
#include <assert.h>
#include "../Headres/LinkedList.h"
LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

void LinkedList::add(double a) {
    int size1=this->size();

    el *e = new el(a);

    if(head == nullptr){
        e->previous = e->next = nullptr;
        head = tail = e;
    }
    else{
        el *curent = head;

        // set current as last element or bigger than e
        while(curent->next != nullptr && curent->v <= e->v)
            curent = curent->next;

        // add after last element
        if(curent->next == nullptr && curent->v < e->v){
            curent->next = e;
            e->previous = curent;
            e->next = nullptr;
            tail = e;
        } // add in the middle of list but before current
        else if (curent->previous != nullptr){
            curent->previous->next = e;
            e->previous = curent->previous;
            e->next = curent;
            curent->previous = e;
        } // add before first element
        else {
            e->previous = nullptr;
            curent->previous = e;
            e->next = curent;
            head = e;
        }
    }
    int size2=this->size();
    assert(size1!=size2);
}

void LinkedList::showLeftToRight(){
    assert(this->size()!=0);
    el *e = head;
    while(e!= nullptr){
        std::cout << e->v << ", ";
        e = e->next;
    }
}

void LinkedList::showRightToLeft() {
    assert(this->size()!=0);
    el *e = tail;
    while(e!= nullptr){
        std::cout << e->v << ", ";
        e = e->previous;
    }
}

void LinkedList::removeVal(double val) {
    assert(this->size()!=0);
    int size1=this->size();

    el *current = head;
    el *previous, *next;

    while(current->v != val && current->next != nullptr)
        current = current->next;

    if(current->v == val){
        // only one element in the list
        if(current->previous == nullptr && current->next == nullptr){
            head = tail = nullptr;
        }// irst element
        else if(current->previous == nullptr){
            head = current->next;
            head->previous = nullptr;
        }// last element
        else if(current->next == nullptr){
            tail = current->previous;
            tail->next = nullptr;
        }// element from the middle
        else{
            previous = current->previous;
            next = current->next;

            previous->next = next;
            next->previous = previous;
        }

        delete current;
    }
    int size2=this->size();
    assert(size1!=size2);
}

void LinkedList::removeList() {
    assert(this->size()!=0);
    int  size1=this->size();
    el *current = head;
    el *del;

    while(current != nullptr){
        del = current;
        current = current->next;
        delete del;
    }

    head = tail = nullptr;
    int size2=this->size();
    assert(size1!=size2);
}

int LinkedList::size() {
    el *temp=this->head;
    int counter=0;
    while(temp!= nullptr){
        temp=temp->next;
        counter++;
    }
    return counter;
}



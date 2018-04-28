//
// Created by Natalia on 26.04.2018.
//

//#define NDEBUG
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
        el *current = head;

        // set current as last element or bigger than e
        while(current->next != nullptr && current->v <= e->v)
            current = current->next;

        // add after last element
        if(current->next == nullptr && current->v < e->v){
            current->next = e;
            e->previous = current;
            e->next = nullptr;
            tail = e;
        } // add in the middle of list but before current
        else if (current->previous != nullptr){
            current->previous->next = e;
            e->previous = current->previous;
            e->next = current;
            current->previous = e;
        } // add before first element
        else {
            e->previous = nullptr;
            current->previous = e;
            e->next = current;
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



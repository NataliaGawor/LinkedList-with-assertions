//
// Created by Natalia on 26.04.2018.
//

#ifndef LINKEDLIST_EL_H
#define LINKEDLIST_EL_H

struct el {
    int v;
    el *next;
    el *previous;
    el();
    el(int v);
    el(int v, el *next, el *previous);
};

#endif //LINKEDLIST_EL_H
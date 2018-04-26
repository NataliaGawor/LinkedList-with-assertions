//
// Created by Natalia on 26.04.2018.
//

#ifndef LINKEDLIST_EL_H
#define LINKEDLIST_EL_H

struct el {
    double v;
    el *next;
    el *previous;
    el();
    el(double v);
};

#endif //LINKEDLIST_EL_H
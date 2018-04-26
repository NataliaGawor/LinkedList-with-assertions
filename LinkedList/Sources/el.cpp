//
// Created by Natalia on 26.04.2018.
//
#include "../Headres/el.h"

//el::el(int v) {
//    this->v = v;
//    this->next = nullptr;
//    this->previous = nullptr;
//}

el::el() : next(nullptr), previous(nullptr) {}

el::el(int v) : v(v), next(nullptr), previous(nullptr) {}

el::el(int v, el *next, el *previous) : v(v), next(next), previous(previous) {}

#ifndef NODE_H
#define NODE_H

#include "MPointer.h"

template <typename T>
class Nodo {
public:
    MPointer<T> data;
    MPointer<Nodo<T>> next;
    MPointer<Nodo<T>> prev;

    Nodo(T value) : data(MPointer<T>::New()) {
        *data = value;
        next = nullptr;
        prev = nullptr;
    }
};

#endif // NODE_H
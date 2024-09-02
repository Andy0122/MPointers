#ifndef NODE_H
#define NODE_H

#include "MPointer.h"

template <typename T>
class Node {
public:
    MPointer<T> data;
    MPointer<Node<T>> next;
    MPointer<Node<T>> prev;

    Node(T value) : data(MPointer<T>::New()) {
        *data = value;
        next = nullptr;
        prev = nullptr;
    }
};

#endif // NODE_H
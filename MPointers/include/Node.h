#ifndef NODE_H
#define NODE_H

#include "MPointerBase.h"

class Node {
private:
    int id;
    int refCount;
    MPointerBase* mpointer;  // Puntero al MPointer
    Node* next;  // Puntero al siguiente nodo en la lista

public:
    Node(int _id, MPointerBase* _mpointer)
        : id(_id), refCount(1), mpointer(_mpointer), next(nullptr) {}

    ~Node() {}

    int getId() const { return id; }

    Node* getNext() const { return next; }

    void setNext(Node* nextNode) { next = nextNode; }

    void incrementRefCount() { refCount++; }

    void decrementRefCount() { refCount--; }

    int getRefCount() const { return refCount; }

    MPointerBase* getMPointer() const { return mpointer; }  // Obtener el MPointer almacenado

    void setMPointer(MPointerBase* ptr) { mpointer = ptr; }
};

#endif // NODE_H

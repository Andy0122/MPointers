#include "../include/RefCountList.h"

RefCountList::RefCountList() : head(nullptr) {}

void RefCountList::Add(NodeBase* newNode) {
    newNode->setNext(head);
    head = newNode;
}


void RefCountList::IncrementRefCount(int id) {
    NodeBase* current = head;
    while (current != nullptr) {
        if (current->getId() == id) {
            current->incrementRefCount();
            return;
        }
        current = current->getNext();
    }
}

void RefCountList::DecrementRefCount(int id) {
    NodeBase* current = head;
    while (current != nullptr) {
        if (current->getId() == id) {
            current->decrementRefCount();
            return;
        }
        current = current->getNext();
    }
}

NodeBase* RefCountList::getHead() const {
    return head;
}

void RefCountList::CleanUp() {
    NodeBase* current = head;
    NodeBase* previous = nullptr;

    while (current != nullptr) {
        NodeBase* nextNode = current->getNext();

        if (current->getRefCount() == 0) {
            if (previous == nullptr) {
                head = nextNode;
            } else {
                previous->setNext(nextNode);
            }
            delete current;
        } else {
            previous = current;
        }
        current = nextNode;
    }
}

RefCountList::~RefCountList() {
    NodeBase* current = head;
    while (current != nullptr) {
        NodeBase* nextNode = current->getNext();
        delete current;
        current = nextNode;
    }
}

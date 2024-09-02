#include "../include/RefCountList.h"
#include "../include/MPointerBase.h"
#include <iostream>


RefCountList::RefCountList() : head(nullptr) {}

Node* RefCountList::getHead() const {
    return head;
}

void RefCountList::Add(int id, MPointerBase* ptr) {
    Node* newNode = new Node(id, ptr);
    newNode->next = head;
    head = newNode;
}

void RefCountList::removeNode(Node* node) {
    if (head == nullptr || node == nullptr) {
        return;
    }

    if (head == node) {
        head = node->next;
        delete node;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next != node) {
        current = current->next;
    }

    if (current->next == node) {
        current->next = node->next;
        delete node;
    }
}

void RefCountList::IncrementRefCount(int id) {
    Node* current = head;
    while (current != nullptr) {
        if (current->id == id) {
            current->refCount++;
            return;
        }
        current = current->next;
    }
}

void RefCountList::DecrementRefCount(int id) {
    Node* current = head;
    while (current != nullptr) {
        if (current->id == id) {
            current->refCount--;
            return;
        }
        current = current->next;
    }
}

void RefCountList::CleanUp() {
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr) {
        Node* nextNode = current->next;  // Guarda el siguiente nodo antes de potencialmente eliminar el actual

        if (current->refCount == 0) {
            std::cout << "Attempting to delete ptr with id: " << current->id << std::endl;
            if (current->ptr != nullptr) {
                delete current->ptr;  // Elimina el objeto al que apunta el nodo
                current->ptr = nullptr;  // Evita el acceso a memoria ya liberada
                std::cout << "Deleted ptr with id: " << current->id << std::endl;
            }

            if (previous == nullptr) {
                // Si estamos eliminando la cabeza de la lista
                head = current->next;
                delete current;
                current = head;  // Avanza al siguiente nodo después de eliminar
            } else {
                previous->next = nextNode;
                delete current;
                current = nextNode;  // Avanza al siguiente nodo después de eliminar
            }
        } else {
            previous = current;
            current = nextNode;  // Avanza al siguiente nodo
        }
    }
}

int RefCountList::GetRefCount(int id) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->id == id) {
            return current->refCount;
        }
        current = current->next;
    }
    return 0; // Si no se encuentra el id, devolver 0
}

RefCountList::~RefCountList() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}
#include "../include/RefCountList.h"
#include "../include/Node.h"
#include <iostream>
#include <mutex>

RefCountList::RefCountList() : head(nullptr) {}


void RefCountList::Add(Node* newNode) {
    std::lock_guard<std::mutex> lock(mtx);  // Protege el acceso a la lista durante la adición de un nuevo nodo
    newNode->setNext(head);
    head = newNode;
}

void RefCountList::IncrementRefCount(int id) {
    std::lock_guard<std::mutex> lock(mtx);  // Protege el acceso a la lista durante la actualización del contador
    Node* current = head;
    while (current != nullptr) {
        if (current->getId() == id) {
            current->incrementRefCount();
            return;
        }
        current = current->getNext();
    }
}

void RefCountList::DecrementRefCount(int id) {
    std::lock_guard<std::mutex> lock(mtx);
    Node* current = head;
    while (current != nullptr) {
        if (current->getId() == id) {
            current->decrementRefCount();
            return;
        }
        current = current->getNext();
    }
}

Node* RefCountList::getHead() const {
    return head;
}

void RefCountList::CleanUp() {
    std::lock_guard<std::mutex> lock(mtx);  // Bloquear el acceso a la lista durante la limpieza
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr) {
        Node* nextNode = current->getNext();

        // Solo eliminar si el RefCount es 0 y el MPointer ha sido destruido
        if (current->getRefCount() == 0 && current->getMPointer() == nullptr) {
            std::cout << "Eliminando nodo con ID: " << current->getId() << "\n";

            // Eliminar el nodo de la lista enlazada
            if (previous == nullptr) {
                head = nextNode;  // Ajustar la cabeza si estamos eliminando el primer nodo
            } else {
                previous->setNext(nextNode);  // Ajustar el enlace del nodo anterior
            }

            delete current;  // Liberar la memoria del nodo
        } else {
            previous = current;
        }

        current = nextNode;
    }
}


RefCountList::~RefCountList() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->getNext();
        delete current;
        current = nextNode;
    }
}

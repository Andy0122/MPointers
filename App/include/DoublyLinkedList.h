#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "Node.h"
#include "MPointer.h"

template <typename T>
class DoublyLinkedList {
private:
    MPointer<Node<T>> head;
    MPointer<Node<T>> tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    bool isEmpty() const {
        return head == nullptr;
    }

    void append(T value) {
        MPointer<Node<T>> newNode = MPointer<Node<T>>::New();
        *newNode = Node<T>(value);

        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            (*tail)->next = newNode;
            (*newNode)->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void prepend(T value) {
        MPointer<Node<T>> newNode = MPointer<Node<T>>::New();
        *newNode = Node<T>(value);

        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            (*head)->prev = newNode;
            (*newNode)->next = head;
            head = newNode;
        }
        size++;
    }

    void removeHead() {
        if (isEmpty()) {
            return;
        }

        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = (*head)->next;
            (*head)->prev = nullptr;
        }
        size--;
    }

    void removeTail() {
        if (isEmpty()) {
            return;
        }

        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            tail = (*tail)->prev;
            (*tail)->next = nullptr;
        }
        size--;
    }

    // Acceso a nodos
    MPointer<Node<T>> getHead() const {
        return head;
    }

    MPointer<Node<T>> getTail() const {
        return tail;
    }

    // Metodo para obtener un nodo en una posición específica
    MPointer<Node<T>> getNodeAt(int index) const {
        if (index < 0 || index >= size) {
            return nullptr;  // Índice fuera de rango
        }

        MPointer<Node<T>> current;
        if (index < size / 2) {
            current = head;
            for (int i = 0; i < index; i++) {
                current = (*current)->next;
            }
        } else {
            current = tail;
            for (int i = size - 1; i > index; i--) {
                current = (*current)->prev;
            }
        }
        return current;
    }

    // Metodo para intercambiar los datos de dos nodos
    void swap(MPointer<Node<T>> node1, MPointer<Node<T>> node2) {
        if (node1 != nullptr && node2 != nullptr) {
            T temp = *(*node1)->data;
            *(*node1)->data = *(*node2)->data;
            *(*node2)->data = temp;
        }
    }

    void printList() const {
        MPointer<Node<T>> current = head;
        while (current != nullptr) {
            std::cout << *(*current)->data << " ";
            current = (*current)->next;
        }
        std::cout << std::endl;
    }
};

#endif // DOUBLYLINKEDLIST_H

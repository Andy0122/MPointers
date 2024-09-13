#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "MPointer.h"

template<typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;  // Valor del nodo
        MPointer<Node> prev;  // Puntero al nodo anterior
        MPointer<Node> next;  // Puntero al siguiente nodo

        Node(T value) : data(value), prev(nullptr), next(nullptr) {}
        // Constructor por defecto
        Node() : data(T()), prev(nullptr), next(nullptr) {}
    };

    MPointer<Node> head;  // Cabeza de la lista
    MPointer<Node> tail;  // Cola de la lista
    int listSize;  // Tamaño de la lista

public:
    // Constructor de la lista
    DoublyLinkedList() : head(nullptr), tail(nullptr), listSize(0) {}

    // Obtener el tamaño de la lista
    int size() const {
        return listSize;
    }

    // Obtener el valor de un nodo en una posición específica
    T get(int index) const {
        if (index < 0 || index >= listSize) {
            throw std::out_of_range("Índice fuera de rango");
        }
        MPointer<Node> current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }

    // Modificar el valor de un nodo en una posición específica
    void set(int index, T value) {
        if (index < 0 || index >= listSize) {
            throw std::out_of_range("Índice fuera de rango");
        }
        MPointer<Node> current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->data = value;
    }

    // Insertar un nuevo elemento al final de la lista
    void append(T value) {
        MPointer<Node> newNode = MPointer<Node>::New();  // Crear un nuevo nodo con MPointer
        *newNode = Node(value);  // Asignar el valor al nodo

        if (tail == nullptr) {  // Lista vacía
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;  // El nuevo nodo apunta a la cola actual
            tail->next = newNode;  // La cola actual apunta al nuevo nodo
            tail = newNode;  // Actualizar la cola
        }
        listSize++;
    }

    // Insertar un nuevo nodo en una posición específica
    void insertAt(T value, int index) {
        if (index < 0 || index > listSize) {
            throw std::out_of_range("Índice fuera de rango");
        }

        MPointer<Node> newNode = MPointer<Node>::New();  // Crear un nuevo nodo con MPointer
        *newNode = Node(value);  // Asignar el valor al nodo

        if (index == 0) {  // Insertar en la cabeza
            newNode->next = head;
            if (head != nullptr) {
                head->prev = newNode;
            }
            head = newNode;
            if (listSize == 0) {
                tail = newNode;  // Si la lista estaba vacía
            }
        } else if (index == listSize) {  // Insertar en la cola
            append(value);
            return;
        } else {
            MPointer<Node> current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next != nullptr) {
                current->next->prev = newNode;
            }
            current->next = newNode;
        }
        listSize++;
    }
/*
    // Eliminar un nodo con un valor específico
    void remove(T value) {
        MPointer<Node> current = head;

        // Recorrer la lista en busca del valor
        while (current != nullptr) {
            if (current->data == value) {
                std::cout << "Eliminando nodo con valor: " << value << std::endl;
                std::cout << "Puntero actual: " << current.getPointer() << std::endl;
                std::cout << "Puntero prev: " << (current->prev != nullptr ? current->prev.getPointer() : nullptr) << std::endl;
                std::cout << "Puntero next: " << (current->next != nullptr ? current->next.getPointer() : nullptr) << std::endl;

                // Ajustar el puntero 'next' del nodo anterior si existe
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;  // Si es el primer nodo, actualizar la cabeza
                }

                // Ajustar el puntero 'prev' del nodo siguiente si existe
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;  // Si es el último nodo, actualizar la cola
                }

                // Establecer los punteros del nodo actual a nullptr
                current->prev = nullptr;
                current->next = nullptr;

                current = nullptr;  // Esto eliminará el nodo de forma segura

                listSize--;  // Reducir el tamaño de la lista
                return;  // Salir de la función después de eliminar el nodo
            }
            current = current->next;
        }
    }
*/

    // Imprimir la lista hacia adelante
    void printForward() const {
        MPointer<Node> current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Imprimir la lista hacia atrás
    void printBackward() const {
        MPointer<Node> current = tail;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }

    void swap(int index1, int index2) {
        if (index1 == index2) return;

        // Obtener los nodos en las posiciones index1 y index2
        MPointer<Node> node1 = getNodeAt(index1);
        MPointer<Node> node2 = getNodeAt(index2);

        if (node1 == nullptr || node2 == nullptr) return;

        // Intercambiar los datos de los nodos
        std::swap(node1->data, node2->data);
    }

    MPointer<Node> getNodeAt(int index) const {
        if (index < 0 || index >= listSize) {
            return nullptr;  // Retorna nullptr si el índice es inválido
        }

        MPointer<Node> current = head;
        for (int i = 0; i < index && current != nullptr; i++) {
            current = current->next;
        }
        return current;
    }

    // Sobrecarga del operador [] para acceder a los elementos por índice
    int& operator[](int index) {
        MPointer<Node> node = getNodeAt(index);
        if (node == nullptr) {
            throw std::out_of_range("Índice fuera de rango");
        }
        return node->data;
    }

    // Destructor para limpiar los nodos
    ~DoublyLinkedList() {
        MPointer<Node> current = head;
        while (current != nullptr) {
            MPointer<Node> next = current->next;
            current = next;
        }
    }
};

#endif  // DOUBLY_LINKED_LIST_H

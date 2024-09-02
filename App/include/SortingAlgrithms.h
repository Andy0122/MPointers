#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include "DoublyLinkedList.h"

// Bubble Sort
template <typename T>
void bubbleSort(DoublyLinkedList<T>& list) {
    if (list.isEmpty()) {return;}
    bool swapped;
    int n = list.getSize();
    do {
        swapped = false;
        MPointer<Node<T>> current = list.getHead();
        for (int i = 0; i < n - 1; i++) {
            MPointer<Node<T>> nextNode = (*current)->next;
            if (*(*current)->data > *(*nextNode)->data) {
                list.swap(current, nextNode);
                swapped = true;
            }
            current = nextNode;
        }
        n--;  // Reduce el número de elementos a revisar después de cada iteración
    } while (swapped);
}

// Insertion Sort
template <typename T>
void insertionSort(DoublyLinkedList<T>& list) {
    if (list.isEmpty()) {
        return;
    }
    MPointer<Node<T>> current = list.getHead()->next;  // Comienza con el segundo nodo
    while (current != nullptr) {
        T key = *(*current)->data;
        MPointer<Node<T>> prev = (*current)->prev;
        // Mueve los elementos de la lista que son mayores que la clave
        // a una posición adelante de su posición actual
        while (prev != nullptr && *(*prev)->data > key) {
            *(*prev->next)->data = *(*prev)->data;
            prev = (*prev)->prev;
        }
        // Coloca la clave en la posición correcta
        if (prev == nullptr) {
            *(*list.getHead())->data = key;
        } else {
            *(*prev->next)->data = key;
        }
        current = (*current)->next;
    }
}

// Función auxiliar para particionar la lista
template <typename T>
MPointer<Node<T>> partition(MPointer<Node<T>> low, MPointer<Node<T>> high) {
    T pivot = *(*high)->data;  // Selecciona el último elemento como pivote
    MPointer<Node<T>> i = low->prev;
    for (MPointer<Node<T>> j = low; j != high; j = (*j)->next) {
        if (*(*j)->data <= pivot) {
            i = (i == nullptr) ? low : (*i)->next;  // Incrementa i si es nullptr
            // Intercambia los datos en i y j
            T temp = *(*i)->data;
            *(*i)->data = *(*j)->data;
            *(*j)->data = temp;
        }
    }
    i = (i == nullptr) ? low : (*i)->next;  // Incrementa i para el último intercambio
    // Intercambia los datos en i y high (pivote)
    T temp = *(*i)->data;
    *(*i)->data = *(*high)->data;
    *(*high)->data = temp;
    return i;
}

// Implementación de QuickSort para la lista doblemente enlazada
template <typename T>
void quickSort(MPointer<Node<T>> low, MPointer<Node<T>> high) {
    if (high != nullptr && low != high && low != (*high)->next) {
        MPointer<Node<T>> pivotNode = partition(low, high);
        quickSort(low, (*pivotNode)->prev);
        quickSort((*pivotNode)->next, high);
    }
}

// Función de conveniencia para llamar a quickSort desde la clase DoublyLinkedList
template <typename T>
void quickSort(DoublyLinkedList<T>& list) {
    quickSort(list.getHead(), list.getTail());
}

#endif // SORTING_ALGORITHMS_H


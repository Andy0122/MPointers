#include <iostream>
#include "DoublyLinkedList.h"
#include "SortingAlgrithms.h"

int main() {
    DoublyLinkedList<int> list;

    // Insertar elementos en la lista
    list.append(12);
    list.append(11);
    list.append(13);
    list.append(5);
    list.append(6);

    std::cout << "Lista antes de ordenar: ";
    list.printForward();

    // Llamada a insertionSort
    insertionSort(list);

    std::cout << "Lista después de ordenar: ";
    list.printForward();

    return 0;
}


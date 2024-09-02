#include "DoublyLinkedList.h"
#include "include/SortingAlgrithms.h"
#include "MPointerGC.h"

int main() {
    MPointerGC& gc = MPointerGC::getInstance();

    DoublyLinkedList<int> list;

    // Agregar 10 elementos desordenados a la lista
    list.append(5);
    list.append(3);
    list.append(8);
    list.append(1);
    list.append(9);
    list.append(2);
    list.append(7);
    list.append(10);
    list.append(4);
    list.append(6);

    std::cout << "Lista original: ";
    list.printList();  // Debería imprimir: 5 3 8 1 9 2 7 10 4 6

    // Estado de la memoria antes de ordenar
    std::cout << "\nEstado de la memoria antes de ordenar:" << std::endl;
    gc.debug();

    // Ordenar con Bubble Sort
    std::cout << "\nOrdenando con Bubble Sort..." << std::endl;
    bubbleSort(list);
    std::cout << "Lista después de Bubble Sort: ";
    list.printList();  // Debería imprimir: 1 2 3 4 5 6 7 8 9 10

    // Estado de la memoria después de Bubble Sort
    std::cout << "\nEstado de la memoria después de Bubble Sort:" << std::endl;
    gc.debug();

    // Resetear la lista a su estado original desordenado
    list = DoublyLinkedList<int>();
    list.append(5);
    list.append(3);
    list.append(8);
    list.append(1);
    list.append(9);
    list.append(2);
    list.append(7);
    list.append(10);
    list.append(4);
    list.append(6);

    // Ordenar con Insertion Sort
    std::cout << "\nOrdenando con Insertion Sort..." << std::endl;
    insertionSort(list);
    std::cout << "Lista después de Insertion Sort: ";
    list.printList();  // Debería imprimir: 1 2 3 4 5 6 7 8 9 10

    // Estado de la memoria después de Insertion Sort
    std::cout << "\nEstado de la memoria después de Insertion Sort:" << std::endl;
    gc.debug();

    // Resetear la lista a su estado original desordenado
    list = DoublyLinkedList<int>();
    list.append(5);
    list.append(3);
    list.append(8);
    list.append(1);
    list.append(9);
    list.append(2);
    list.append(7);
    list.append(10);
    list.append(4);
    list.append(6);

    // Ordenar con QuickSort
    std::cout << "\nOrdenando con QuickSort..." << std::endl;
    quickSort(list);
    std::cout << "Lista después de QuickSort: ";
    list.printList();  // Debería imprimir: 1 2 3 4 5 6 7 8 9 10

    // Estado de la memoria después de QuickSort
    std::cout << "\nEstado de la memoria después de QuickSort:" << std::endl;
    gc.debug();

    return 0;
}
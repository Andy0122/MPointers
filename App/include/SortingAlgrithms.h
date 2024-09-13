#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include "DoublyLinkedList.h"

void bubbleSort(DoublyLinkedList<int>& list) {
    int n = list.size();  // Obtenemos el tamaño de la lista

    // Bucle externo que corresponde al número de elementos a ordenar
    for (int i = 0; i < n - 1; i++) {
        // Bucle interno para comparar nodos adyacentes por índice
        for (int j = 0; j < n - i - 1; j++) {
            // Si los nodos adyacentes están en el orden incorrecto, intercambiamos
            if (list[j] > list[j + 1]) {
                list.swap(j, j + 1);  // Intercambia nodos completos
            }
        }
    }
}

int partition(DoublyLinkedList<int>& list, int low, int high) {

    // Seleccionar el último elemento como pivote
    int pivot = list[high];

    // Índice del elemento justo antes del último
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {

        // Si el elemento actual es menor o igual que el pivote
        if (list[j] <= pivot) {
            i++;
            list.swap(i, j);
        }
    }

    // Poner el pivote en su posición correcta
    list.swap(i + 1, high);

    // Devolver el índice de partición
    return (i + 1);
}
void quickSort(DoublyLinkedList<int>& list, int low, int high) {

    // Caso base: continuar hasta que low sea menor que high
    if (low < high) {

        // pi es el índice de partición, list[pi] está en la posición correcta
        int pi = partition(list, low, high);

        // Ordenar recursivamente los elementos antes y después de la partición
        quickSort(list, low, pi - 1);
        quickSort(list, pi + 1, high);
    }
}

void insertionSort(DoublyLinkedList<int>& list) {
    int n = list.size();  // Obtenemos el tamaño de la lista

    // Empezamos desde el segundo elemento
    for (int i = 1; i < n; ++i) {
        int key = list[i];  // El elemento que queremos ordenar
        int j = i - 1;

        // Mover los elementos que son mayores que `key` una posición adelante
        while (j >= 0 && list[j] > key) {
            list[j + 1] = list[j];  // Desplazar el elemento hacia adelante
            j = j - 1;
        }
        list[j + 1] = key;  // Insertar el elemento en la posición correcta
    }
}

#endif // SORTING_ALGORITHMS_H


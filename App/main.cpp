#include <iostream>
#include "DoublyLinkedList.h"
#include "SortingAlgrithms.h"
#include <cstdlib> // Para srand() y rand()
#include <ctime>   // Para time()
#include <chrono>  // Para medir el tiempo

// Función para generar una lista con números aleatorios
void generarNumerosAleatorios(DoublyLinkedList<int>& list, int cantidad) {
    srand(static_cast<unsigned>(time(0)));  // Inicializa el generador de números aleatorios con el tiempo actual
    for (int i = 0; i < cantidad; ++i) {
        int numeroAleatorio = rand() % 1000 + 1;  // Genera un número aleatorio entre 1 y 1000
        list.append(numeroAleatorio);
    }
}

int main() {

    MPointerGC& gc = MPointerGC::getInstance();

    const int cantidadNumeros = 100;

    // Crear una lista de números aleatorios
    DoublyLinkedList<int> listaBubbleSort;
    DoublyLinkedList<int> listaQuickSort;
    DoublyLinkedList<int> listaInsertionSort;

    generarNumerosAleatorios(listaBubbleSort, cantidadNumeros);

    // Copiar la lista generada para probar diferentes algoritmos
    for (int i = 0; i < listaBubbleSort.size(); ++i) {
        listaQuickSort.append(listaBubbleSort.getAt(i));
        listaInsertionSort.append(listaBubbleSort.getAt(i));
    }

    std::cout << "=== Lista Original ===" << std::endl;
    listaBubbleSort.printForward();

    // Medir tiempo para Bubble Sort
    auto inicioBubble = std::chrono::high_resolution_clock::now();
    bubbleSort(listaBubbleSort);
    auto finBubble = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracionBubble = finBubble - inicioBubble;
    std::cout << "\n=== Lista Ordenada con Bubble Sort ===" << std::endl;
    listaBubbleSort.printForward();
    std::cout << "Duración de Bubble Sort: " << duracionBubble.count() << " segundos\n";

    // Medir tiempo para Quick Sort
    auto inicioQuick = std::chrono::high_resolution_clock::now();
    quickSort(listaQuickSort, 0, listaQuickSort.size() - 1);
    auto finQuick = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracionQuick = finQuick - inicioQuick;
    std::cout << "\n=== Lista Ordenada con Quick Sort ===" << std::endl;
    listaQuickSort.printForward();
    std::cout << "Duración de Quick Sort: " << duracionQuick.count() << " segundos\n";

    // Medir tiempo para Insertion Sort
    auto inicioInsertion = std::chrono::high_resolution_clock::now();
    insertionSort(listaInsertionSort);
    auto finInsertion = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracionInsertion = finInsertion - inicioInsertion;
    std::cout << "\n=== Lista Ordenada con Insertion Sort ===" << std::endl;
    listaInsertionSort.printForward();
    std::cout << "Duración de Insertion Sort: " << duracionInsertion.count() << " segundos\n";

    return 0;
}


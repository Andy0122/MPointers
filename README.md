# MPointers
Este proyecto implementa una biblioteca de MPointers para manejar la gestión automática de memoria y una lista doblemente enlazada que utiliza MPointers. Además, se incluyen implementaciones de algoritmos de ordenamiento (QuickSort, BubbleSort, InsertionSort) adaptados para trabajar con la lista doblemente enlazada.

Contenido
Introducción
Instalación
Estructura del Proyecto
Descripción de MPointer
Lista Doblemente Enlazada
Algoritmos de Ordenamiento
Ejemplos de Uso
Consideraciones Técnicas


Introducción
Este proyecto proporciona una biblioteca que incluye:

MPointer: Un puntero inteligente que gestiona automáticamente la memoria utilizando un recolector de basura.
DoublyLinkedList: Una lista doblemente enlazada que usa MPointer para gestionar sus nodos.
Implementaciones de QuickSort, BubbleSort y InsertionSort adaptadas para la lista doblemente enlazada.
Objetivos:
Proporcionar un entorno seguro para la gestión de memoria sin fugas ni errores comunes asociados con punteros crudos.
Ofrecer una estructura de datos eficiente (lista doblemente enlazada) que permita trabajar con los algoritmos de ordenamiento mencionados.

Instalación
Requisitos:
C++20 o superior.
Un entorno de desarrollo que soporte C++ (por ejemplo, CLion, Visual Studio Code, etc.).
CMake para gestionar la construcción del proyecto.
Pasos:
Clona el repositorio:

git clone <url-del-repositorio>
cd <nombre-del-repositorio>

Configura el entorno de construcción con CMake:

mkdir build
cd build
cmake ..
make


Ejecuta los ejemplos proporcionados:

./App


Estructura del Proyecto

proyecto/
│
├── MPointers/
│   ├── include/
│   │   ├── MPointer.h      // Implementación del MPointer
│   │   ├── MPointerBase.h  // Clase base abstracta para MPointer
│   │   ├── MPointerGC.h    // Recolector de basura para gestionar MPointers
│   │   ├── Node.h          // Nodo de la lista doblemente enlazada
│   │   └── RefCountList.h  // Lista de contadores de referencias
│   ├── src/
│   │   ├── MPointerGC.cpp  // Definición del recolector de basura
│   │   ├── RefCountList.cpp// Definición de la lista de contadores
│
├── App/
│   ├── include/
│   │   ├── DoublyLinkedList.h // Implementación de la lista doblemente enlazada
│   ├── src/
│   │   └── main.cpp        // Ejemplo de uso de la biblioteca
│
├── CMakeLists.txt          // Configuración de CMake
└── README.md               // Este archivo


Descripción de MPointer
¿Qué es un MPointer?
MPointer es un puntero inteligente diseñado para gestionar automáticamente la memoria, similar a los shared_ptr en C++. Funciona en conjunto con un recolector de basura (MPointerGC) que monitoriza el uso de estos punteros y los elimina cuando ya no son referenciados.

Métodos Principales:
MPointer<T> New(): Crea un nuevo MPointer que gestiona un puntero de tipo T.
*T& operator()**: Sobrecarga para acceder al valor apuntado por el puntero.
*T operator->()**: Sobrecarga para acceder a los miembros de la clase apuntada.
int getId(): Devuelve el identificador único del MPointer.
void deletePointer(): Elimina manualmente el puntero gestionado (usado internamente por el GC).


Ejemplo de Uso de MPointer:

MPointer<int> mp1 = MPointer<int>::New();
*mp1 = 100;
std::cout << "Valor almacenado: " << *mp1 << std::endl;


Lista Doblemente Enlazada
La DoublyLinkedList implementa una lista doblemente enlazada utilizando MPointer para gestionar los nodos, lo que asegura una gestión automática de la memoria.

Métodos Principales:
void append(T value): Añade un valor al final de la lista.
void insertAt(T value, int index): Inserta un valor en una posición específica.
void swap(int index1, int index2): Intercambia los valores en las posiciones index1 y index2.
T get(int index): Devuelve el valor almacenado en una posición específica.
int size(): Devuelve el tamaño de la lista.


Ejemplo de Uso de la Lista:

DoublyLinkedList<int> list;
list.append(10);
list.append(20);
list.insertAt(15, 1);
std::cout << "Valor en la posición 1: " << list.get(1) << std::endl;


Algoritmos de Ordenamiento
Se implementan tres algoritmos de ordenamiento adaptados para la lista doblemente enlazada:

QuickSort: Un algoritmo de ordenamiento rápido que divide la lista en sublistas.
BubbleSort: Un algoritmo de ordenamiento simple basado en la comparación e intercambio de elementos adyacentes.
InsertionSort: Ordena la lista insertando cada elemento en su posición correcta dentro de la lista ya ordenada.

Ejemplo de BubbleSort:

DoublyLinkedList<int> list;
list.append(30);
list.append(10);
list.append(20);
BubbleSort::bubbleSort(list);
list.printForward();  // Resultado: 10 20 30


Ejemplo de QuickSort:

DoublyLinkedList<int> list;
list.append(40);
list.append(20);
list.append(10);
QuickSort::quickSort(list, 0, list.size() - 1);
list.printForward();  // Resultado: 10 20 40

Ejemplos de Uso
Aquí se muestra cómo utilizar la biblioteca MPointer junto con la lista doblemente enlazada y los algoritmos de ordenamiento.


#include "DoublyLinkedList.h"
#include "QuickSort.h"
#include "BubbleSort.h"

int main() {
    // Crear lista
    DoublyLinkedList<int> list;
    list.append(30);
    list.append(10);
    list.append(50);

    // Ordenar usando BubbleSort
    BubbleSort::bubbleSort(list);
    list.printForward();

    // Ordenar usando QuickSort
    QuickSort::quickSort(list, 0, list.size() - 1);
    list.printForward();
    
    return 0;
}

Consideraciones Técnicas
Gestión de Memoria: La biblioteca MPointer gestiona automáticamente la memoria, pero asegúrate de no manipular punteros directamente fuera del contexto de MPointer.
Uso de Algoritmos: Los algoritmos están optimizados para listas pequeñas. Si vas a trabajar con grandes conjuntos de datos, considera realizar pruebas de rendimiento adicionales.
Integración con Otros Proyectos: La biblioteca es fácilmente integrable en cualquier proyecto que requiera manejo eficiente de memoria y ordenamiento.

Créditos
Desarrollado por Dylan Elizondo Picado.

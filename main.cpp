#include <iostream>
#include "../MPointers/include/MPointer.h"
#include "../MPointers/include/MPointerGC.h"


int main() {
    // Inicialización del recolector de basura
    MPointerGC& gc = MPointerGC::getInstance();

    // Crear varios MPointer de tipo int
    MPointer<int> mp1 = MPointer<int>::New();
    *mp1 = 10;

    MPointer<int> mp2 = MPointer<int>::New();
    *mp2 = 20;

    MPointer<int> mp3 = MPointer<int>::New();
    *mp3 = 30;

    std::cout << "Valores iniciales:" << std::endl;
    std::cout << "mp1: " << *mp1 << ", mp2: " << *mp2 << ", mp3: " << *mp3 << std::endl;

    // Copiar mp1 en mp2 (mp2 ahora apunta al mismo objeto que mp1)
    mp2 = mp1;

    std::cout << "\nDespués de asignar mp1 a mp2:" << std::endl;
    std::cout << "mp1: " << *mp1 << ", mp2: " << *mp2 << ", mp3: " << *mp3 << std::endl;

    // Copiar mp3 en mp1 (mp1 y mp2 ahora apuntan al mismo objeto que mp3)
    mp1 = mp3;

    std::cout << "\nDespués de asignar mp3 a mp1:" << std::endl;
    std::cout << "mp1: " << *mp1 << ", mp2: " << *mp2 << ", mp3: " << *mp3 << std::endl;

    // Crear un nuevo MPointer de tipo int y copiar mp2 en él
    MPointer<int> mp4 = MPointer<int>::New();
    mp4 = mp2;

    std::cout << "\nDespués de asignar mp2 a mp4:" << std::endl;
    std::cout << "mp1: " << *mp1 << ", mp2: " << *mp2 << ", mp3: " << *mp3 << ", mp4: " << *mp4 << std::endl;

    // Mostrar el estado de la memoria (debug)
    std::cout << "\nEstado de la memoria antes de la recolección de basura:" << std::endl;
    gc.debug();

    // Destruir mp3 (esto debería reducir el conteo de referencias para el bloque de memoria compartido por mp1, mp2, y mp4)
    {
        MPointer<int> temp = mp3;
    }  // temp sale de scope y se destruye, esto debería liberar la memoria si es la última referencia

    std::cout << "\nEstado de la memoria después de destruir temp:" << std::endl;
    gc.debug();

    // Recolección de basura forzada
    std::cout << "\nForzando la recolección de basura..." << std::endl;
    gc.collectGarbage();

    std::cout << "\nEstado de la memoria después de la recolección de basura:" << std::endl;
    gc.debug();

    return 0;
}
#include "../include/MPointerGC.h"
#include "../include/MPointer.h"
#include "../include/Node.h"
#include <iostream>

// Constructor privado, arranca el recolector de basura
MPointerGC::MPointerGC() {
    startGC();  // Inicia el GC en un hilo separado
}

// Metodo para iniciar el recolector de basura en un hilo independiente
void MPointerGC::startGC() {
    std::thread([this]() {
        while (running) {
            std::this_thread::sleep_for(std::chrono::seconds(3));  // Pausa de 1 segundo entre ciclos
            collectGarbage();
        }
    }).detach();  // Hilo ejecutado en segundo plano
}

// Metodo estático para obtener la instancia singleton del recolector
MPointerGC& MPointerGC::getInstance() {
    static MPointerGC instance;  // Instancia única del recolector de basura
    return instance;
}

// Añade un nuevo MPointerBase al recolector, creando un nuevo nodo
int MPointerGC::addPointerCount(MPointerBase* ptr) {
    std::lock_guard<std::mutex> lock(mtx);  // Bloquea el acceso concurrente
    int id = nextId++;  // Genera un ID único

    Node* newNode = new Node(id, ptr);  // Crea un nuevo nodo con el MPointerBase
    refCountList.Add(newNode);  // Añade el nodo a la lista de referencias

    return id;  // Devuelve el ID asignado
}

// Incrementa el contador de referencias del MPointer en la lista
void MPointerGC::increasePointerCount(MPointerBase* ptr) {
    std::lock_guard<std::mutex> lock(mtx);  // Protege el acceso concurrente
    int id = ptr->getId();
    refCountList.IncrementRefCount(id);  // Incrementa el contador en la lista enlazada
}

// Decrementa el contador de referencias del MPointer en la lista
void MPointerGC::decreasePointerCount(MPointerBase* ptr) {
    std::lock_guard<std::mutex> lock(mtx);
    int id = ptr->getId();
    //std::cout << "Decreasing pointer count for ID: " << id << std::endl;

    refCountList.DecrementRefCount(id);

    Node* node = refCountList.getHead();
    while (node != nullptr) {
        //std::cout << "Checking node with ID: " << node->getId() << std::endl;
        if (node->getId() == id && node->getRefCount() == 0) {
            //std::cout << "Deleting pointer for node with ID: " << id << std::endl;
            node->getMPointer()->deletePointer();  // Elimina el puntero

            node->setMPointer(nullptr);
            break;
        }
        node = node->getNext();
    }
}

// Ejecuta la recolección de basura, eliminando punteros con referencia cero
void MPointerGC::collectGarbage() {
    std::lock_guard<std::mutex> lock(mtx);  // Bloquea el acceso concurrente
    refCountList.CleanUp();  // Limpia nodos cuyo contador de referencias es 0
}

void MPointerGC::debug() {
    std::lock_guard<std::mutex> lock(mtx);  // Asegurar que no haya condiciones de carrera
    std::cout << "Estado actual de los MPointer gestionados:\n";

    Node* current = refCountList.getHead();
    while (current != nullptr) {
        std::cout << "ID: " << current->getId() << " | RefCount: " << current->getRefCount();

        // Verificamos si el MPointer aún existe (es decir, si el puntero no es nullptr)
        if (current->getMPointer() != nullptr) {
            try {
                std::cout << " | Dirección de memoria: " << current->getMPointer()->getPointer() << "\n";
            } catch (...) {
                std::cout << " | Dirección de memoria: nullptr (Error de acceso)\n";
            }
        } else {
            // Si el MPointer ha sido destruido, mostrar nullptr en la dirección de memoria
            std::cout << " | Dirección de memoria: nullptr\n";
        }

        current = current->getNext();
    }
}
// Destructor que detiene el recolector de basura
MPointerGC::~MPointerGC() {
    running = false;  // Detiene el ciclo del recolector de basura
}



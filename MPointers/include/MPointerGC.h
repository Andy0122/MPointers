#ifndef MPOINTERGC_H
#define MPOINTERGC_H

#include <thread>
#include <chrono>
#include <mutex>
#include "MPointerBase.h"
#include "RefCountList.h"

class MPointerGC {
private:
    RefCountList refCountList;
    std::mutex mtx;
    bool running = true;
    int nextId = 1;

    MPointerGC();  // Declaración, pero no definición
    void startGC();  // Declaración

public:
    static MPointerGC& getInstance();  // Declaración

    template <typename T>
    int addPointerCount(T* ptr) {
        std::lock_guard<std::mutex> lock(mtx);  // Asegura la exclusión mutua
        int id = nextId++;  // Asigna un ID único al puntero

        Node<T>* newNode = new Node<T>(id, ptr);  // Crear un nodo específico para el tipo T
        refCountList.Add(newNode);  // Añadir el nodo a la lista

        return id;  // Retorna el ID asignado
    }

    void increasePointerCount(MPointerBase* ptr);
    void decreasePointerCount(MPointerBase* ptr);
    void collectGarbage();
    void debug();

    ~MPointerGC();

};

#endif // MPOINTERGC_H
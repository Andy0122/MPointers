#ifndef MPOINTERGC_H
#define MPOINTERGC_H

#include <thread>
#include <chrono>
#include <mutex>
#include "MPointerBase.h"
#include "Node.h"
#include "RefCountList.h"

class MPointerGC {
private:
    RefCountList refCountList;  // Lista enlazada para gestionar punteros a MPointerBase
    std::mutex mtx;  // Mutex para proteger el acceso concurrente
    bool running = true;  // Controla si el recolector de basura está en funcionamiento
    int nextId = 1;  // Generador de IDs únicos para los MPointers

    MPointerGC();  // Constructor privado, inicia el GC
    void startGC();  // Metodo que ejecuta el recolector de basura

public:
    static MPointerGC& getInstance();  // Metodo estático para obtener la instancia singleton del GC
    int addPointerCount(MPointerBase* ptr);  // Añade un nuevo MPointerBase al recolector
    void increasePointerCount(MPointerBase* ptr);  // Incrementa el contador de referencias
    void decreasePointerCount(MPointerBase* ptr);  // Decrementa el contador de referencias
    void collectGarbage();  // Ejecuta la recolección de basura
    void debug();  // Declaración del metodo debug
    ~MPointerGC();  // Destructor
};

#endif // MPOINTERGC_H

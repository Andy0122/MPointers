#include "../include/MPointerGC.h"
#include "../include/MPointer.h"
#include <iostream>


MPointerGC::MPointerGC() {
    startGC();  // Inicia el GC en el constructor
}

void MPointerGC::startGC() {
    /*std::thread([this]() {
        while (running) {
            std::this_thread::sleep_for(std::chrono::seconds(10));
            collectGarbage();
        }
    }).detach();*/
}

MPointerGC& MPointerGC::getInstance() {
    static MPointerGC instance;
    return instance;
}

int MPointerGC::addPointerCount(MPointerBase* ptr) {
    std::lock_guard<std::mutex> lock(mtx);  // Asegura la exclusión mutua
    int id = nextId++;  // Asigna un ID único al puntero
    refCountList.Add(id, ptr);  // Agrega el ID y el puntero a la lista de contadores de referencias
    return id;  // Retorna el ID asignado
}

void MPointerGC::increasePointerCount(MPointerBase* ptr) {
    std::lock_guard<std::mutex> lock(mtx);

    int id = ptr->getId();  // Obtén el ID del puntero
    refCountList.IncrementRefCount(id);  // Decrementa el contador de referencias
}

void MPointerGC::decreasePointerCount(MPointerBase* ptr) {
    std::lock_guard<std::mutex> lock(mtx);

    int id = ptr->getId();  // Obtén el ID del puntero
    refCountList.DecrementRefCount(id);  // Decrementa el contador de referencias

}
/*
int MPointerGC::getPointerCount(int id) {
    std::lock_guard<std::mutex> lock(mtx);
    return refCountList.GetRefCount(id);
}
*/
void MPointerGC::collectGarbage() {
    std::lock_guard<std::mutex> lock(mtx);
    refCountList.CleanUp();
}

MPointerGC::~MPointerGC() {
    running = false;
}

void MPointerGC::debug() {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Estado de la memoria:\n";

    Node* current = refCountList.getHead();
    while (current != nullptr) {
        std::cout << "ID: " << current->id
                  << " | RefCount: " << current->refCount
                  << " | Address: " << static_cast<void*>(current->ptr)
                  << std::endl;
        current = current->next;
    }
}

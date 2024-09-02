#include "../include/MPointerGC.h"
#include "../include/MPointer.h"
#include <iostream>


MPointerGC::MPointerGC() {
    startGC();  // Inicia el GC en el constructor
}

void MPointerGC::startGC() {
    std::thread([this]() {
        while (running) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            collectGarbage();
        }
    }).detach();
}

MPointerGC& MPointerGC::getInstance() {
    static MPointerGC instance;
    return instance;
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

void MPointerGC::collectGarbage() {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Collecting garbage..." << std::endl;
    refCountList.CleanUp();
}

MPointerGC::~MPointerGC() {
    running = false;
}

void MPointerGC::debug() {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Estado de la memoria:\n";

    NodeBase* current = refCountList.getHead();
    while (current != nullptr) {
        std::cout << "ID: " << current->getId()
                  << " | RefCount: " << current->getRefCount()
                  << " | Address: " << static_cast<void*>(current->getPtr())
                  << std::endl;
        current = current->getNext();
    }
}

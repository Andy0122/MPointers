#ifndef MPOINTER_H
#define MPOINTER_H

#include <iostream>
#include "MPointerGC.h"
#include "MPointerBase.h"

template <typename T>
class MPointer : public MPointerBase {
private:
    T* ptr;
    int id;

    MPointer() {
        ptr = new T();
        id = MPointerGC::getInstance().addPointerCount(static_cast<void*>(ptr));  // Pasas el puntero a los datos gestionados
    }

public:
    static MPointer<T> New() {
        return MPointer<T>();
    }

    MPointer(const MPointer<T>& other) {
        ptr = other.ptr;
        id = other.id;
        MPointerGC& gc = MPointerGC::getInstance();

        // Decrementar el contador de referencias en el recolector de basura
        gc.increasePointerCount(this);
    }

    void printAttributes() const {
        std::cout << "MPointer ID: " << id << ", Pointer Value: " << *ptr << std::endl;
    }

    // Sobrecarga del operador de asignación para valores del tipo T
    MPointer<T>& operator=(const T& value) {
        *ptr = value;
        return *this;
    }

    MPointer<T>& operator=(const MPointer<T>& other) {
        if (this != &other) {
            MPointerGC::getInstance().decreasePointerCount(this);
            ptr = other.ptr;
            id = other.id;
            MPointerGC::getInstance().increasePointerCount(this);

        }
        return *this;
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    ~MPointer() {
        MPointerGC& gc = MPointerGC::getInstance();
        gc.decreasePointerCount(this);
    }

    int getId() const override {
        return id;
    }
};

#endif // MPOINTER_H
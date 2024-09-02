#ifndef MPOINTER_H
#define MPOINTER_H

#include <iostream>
#include "MPointerGC.h"
#include "MPointerBase.h"  // Asegúrate de incluir la definición completa de MPointerBase

template <typename T>
class MPointer : public MPointerBase {
private:
    T* ptr;
    int id;

    MPointer() {
        ptr = new T();
        id = MPointerGC::getInstance().addPointerCount(this);  // Registra el puntero en el GC y obtiene un ID único
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

        // Decrementar el contador de referencias en el recolector de basura
        gc.decreasePointerCount(this);

        // Si el contador de referencias llega a 0, el recolector de basura será responsable de eliminar el puntero
        // y realizar la limpieza necesaria.
    }

    int getId() const override {
        return id;
    }
};

#endif // MPOINTER_H
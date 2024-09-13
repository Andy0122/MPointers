#ifndef MPOINTER_H
#define MPOINTER_H

#include <iostream>
#include "MPointerGC.h"
#include "MPointerBase.h"

template <typename T>
class MPointer : public MPointerBase {
private:
    T* ptr;  // Puntero al dato gestionado
    int id;  // Identificador único del MPointer

    // Constructor privado
    MPointer() {
        ptr = new T();  // Inicializa un nuevo puntero de tipo T
        id = MPointerGC::getInstance().addPointerCount(this);  // Registra el MPointer en el GC
    }

public:
    // Metodo estático para crear un nuevo MPointer
    static MPointer<T> New() {
        return MPointer<T>();
    }

    // Constructor que acepta nullptr
    MPointer(std::nullptr_t) : ptr(nullptr), id(-1) {}

    // Constructor de copia
    MPointer(const MPointer<T>& other) {
        ptr = other.ptr;
        id = other.id;
        MPointerGC::getInstance().increasePointerCount(this);  // Incrementa el contador de referencias
    }

    // Sobrecarga del operador de asignación
    MPointer<T>& operator=(const MPointer<T>& other) {
        if (this != &other) {
            MPointerGC::getInstance().decreasePointerCount(this);  // Decrementa el contador actual
            ptr = other.ptr;
            id = other.id;
            MPointerGC::getInstance().increasePointerCount(this);  // Incrementa el contador de referencias
        }
        return *this;
    }

    // Sobrecarga del operador = para asignar valores del tipo T directamente al MPointer
    MPointer<T>& operator=(const T& value) {
        *ptr = value;  // Asigna el valor directamente al puntero interno
        return *this;
    }

    // Sobrecarga del operador * para acceder al valor apuntado
    T& operator*() const {
        return *ptr;
    }

    // Sobrecarga del operador -> para acceder a los miembros de T
    T* operator->() const {
        return ptr;
    }

    // Implementación del metodo deletePointer (desde MPointerBase)
    void deletePointer() override {
        delete ptr;  // Elimina el puntero gestionado de tipo T
        ptr = nullptr;  // Asegura que el puntero no quede colgando
    }

    // Implementación del metodo getId (desde MPointerBase)
    int getId() const override {
        return id;
    }

    // Devuelve la dirección de memoria del puntero gestionado
    void* getPointer() const override {
        return static_cast<void*>(ptr);  // Devuelve la dirección del puntero interno
    }


    // Destructor
    ~MPointer() {
        //std::cout << "DESTRUCTOR MPOINTER" << std::endl;
        MPointerGC::getInstance().decreasePointerCount(this);  // Decrementa el contador de referencias al destruirse
    }

    // Sobrecarga de operadores de comparación con nullptr
    bool operator==(std::nullptr_t) const {
        return ptr == nullptr;
    }

    bool operator!=(std::nullptr_t) const {
        return ptr != nullptr;
    }
};

#endif // MPOINTER_H

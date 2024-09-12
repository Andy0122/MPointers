#ifndef MPOINTERBASE_H
#define MPOINTERBASE_H

class MPointerBase {
public:
    virtual ~MPointerBase() = default;

    // Devuelve el ID del MPointer
    virtual int getId() const = 0;

    // Metodo virtual que eliminará el puntero interno gestionado
    virtual void deletePointer() = 0;

    // Devuelve la dirección de memoria del puntero gestionado
    virtual void* getPointer() const = 0;
};

#endif // MPOINTERBASE_H
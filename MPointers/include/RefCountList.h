#ifndef REFCOUNTLIST_H
#define REFCOUNTLIST_H

#include "Node.h"
#include <mutex>

// Forward declaration de la clase Node
class Node;

class RefCountList {
private:
    Node* head;  // Cabeza de la lista enlazada
    std::mutex mtx;   // Mutex para asegurar la exclusión mutua durante las operaciones de limpieza

public:
    RefCountList();

    void Add(Node* newNode);  // Añadir un nuevo nodo a la lista
    void IncrementRefCount(int id);  // Incrementar el contador de referencias
    void DecrementRefCount(int id);  // Decrementar el contador de referencias
    void CleanUp();  // Limpiar la lista eliminando nodos con refCount == 0
    Node* getHead() const;  // Obtener la cabeza de la lista

    ~RefCountList();
};

#endif // REFCOUNTLIST_H

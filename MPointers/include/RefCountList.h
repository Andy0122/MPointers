#ifndef REFCOUNTLIST_H
#define REFCOUNTLIST_H

class MPointerBase;  // Declaración anticipada de MPointerBase

struct Node {
    int id;               // Identificador único de MPointer
    int refCount;         // Contador de referencias
    MPointerBase* ptr;    // Puntero al MPointerBase
    Node* next;           // Puntero al siguiente nodo en la lista

    // Constructor para inicializar un nodo
    Node(int _id, MPointerBase* _ptr) : id(_id), refCount(1), ptr(_ptr), next(nullptr) {}
};

class RefCountList {
private:
    Node* head;           // Cabeza de la lista enlazada

public:
    // Constructor para inicializar la lista
    RefCountList();

    // Meodo para obtener la cabeza de la lista
    Node* getHead() const;

    // Metodo para agregar un nuevo id a la lista
    void Add(int id, MPointerBase* ptr);

    // Metodo para eliminar un nodo específico
    void removeNode(Node* node);

    // Metodo para incrementar el refCount de un id existente
    void IncrementRefCount(int id);

    // Metodo para decrementar el refCount de un id existente
    void DecrementRefCount(int id);

    // Metodo limpiar los nodos que no tengan referencias
    void CleanUp();

    // Metodo para obtener el refCount de un id
    int GetRefCount(int id) const;

    // Destructor para liberar toda la memoria
    ~RefCountList();
};

#endif // REFCOUNTLIST_H
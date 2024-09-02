#ifndef NODE_H
#define NODE_H

class NodeBase {
public:
    virtual ~NodeBase() = default;
    virtual int getId() const = 0;
    //virtual void deletePtr() = 0;
    virtual NodeBase* getNext() const = 0;
    virtual void setNext(NodeBase* nextNode) = 0;
    virtual int getRefCount() const = 0;
    virtual void incrementRefCount() = 0;
    virtual void decrementRefCount() = 0;
    virtual void* getPtr() const = 0;
};

// Definición de Node<T> como una plantilla
template <typename T>
class Node : public NodeBase {
private:
    int id;
    int refCount;
    T* ptr;  // Puntero al tipo T
    NodeBase* next;  // Puntero al siguiente nodo en la lista

public:
    Node(int _id, T* _ptr)
        : id(_id), refCount(1), ptr(_ptr), next(nullptr) {}

    ~Node() override {
        delete ptr;  // Libera el puntero específico cuando se destruye el nodo
        ptr = nullptr;
    }

    int getId() const override {
        return id;
    }
    /*
    void deletePtr() override {
        delete ptr;
        ptr = nullptr;
    }
    */
    NodeBase* getNext() const override {
        return next;
    }

    void setNext(NodeBase* nextNode) override {
        next = nextNode;
    }

    void incrementRefCount() override {
        refCount++;
    }

    void decrementRefCount() override {
        refCount--;
    }

    int getRefCount() const override {
        return refCount;
    }
    void* getPtr() const override {
        return static_cast<void*>(ptr);  // Devuelve el puntero gestionado como un void*
    }
};

#endif // NODE_H

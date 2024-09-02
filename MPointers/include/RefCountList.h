#ifndef REFCOUNTLIST_H
#define REFCOUNTLIST_H

#include "Node.h"

class RefCountList {
private:
    NodeBase* head;

public:
    RefCountList();

    void Add(NodeBase* newNode);
    void IncrementRefCount(int id);
    void DecrementRefCount(int id);
    void CleanUp();
    NodeBase* getHead() const;

    ~RefCountList();
};

#endif // REFCOUNTLIST_H
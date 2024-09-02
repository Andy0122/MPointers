#ifndef MPOINTERGC_H
#define MPOINTERGC_H

#include <list>
#include <thread>
#include <chrono>
#include <mutex>
#include "MPointerBase.h"
#include "RefCountList.h"

class MPointerGC {
private:
    RefCountList refCountList;
    std::mutex mtx;
    bool running = true;
    int nextId = 1;

    MPointerGC();  // Declaración, pero no definición
    void startGC();  // Declaración

public:
    static MPointerGC& getInstance();  // Declaración

    int addPointerCount(MPointerBase* ptr);
    void increasePointerCount(MPointerBase* ptr);
    void decreasePointerCount(MPointerBase* ptr);
    //int getPointerCount(int id);
    void collectGarbage();
    void debug();

    ~MPointerGC();

};

#endif // MPOINTERGC_H
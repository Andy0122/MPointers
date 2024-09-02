#include <iostream>
#include "../MPointers/include/MPointer.h"
#include "../MPointers/include/MPointerGC.h"

MPointer<int> foo() {
    MPointerGC& gc = MPointerGC::getInstance();

    MPointer<int> temp2 = MPointer<int>::New();
    MPointer<int> temp = MPointer<int>::New();
    temp = 666;
    MPointerGC::getInstance().debug();
    return temp;
}

int main()
{
    MPointerGC& gc = MPointerGC::getInstance();

    MPointer<int> mp1 = MPointer<int>::New();
    MPointer<int> mp2 = MPointer<int>::New();
    MPointer<bool> bP = MPointer<bool>::New();
    MPointer<bool> bP2 = bP;
    bP = true;
    foo();

    MPointerGC::getInstance().debug();

    *mp1 = 100;
    mp2 = 55;

    MPointer<int> mp3 = mp2;
    MPointerGC::getInstance().debug();

    mp3 = mp1;
    MPointerGC::getInstance().debug();

    // Simulate some work to let the GC run:
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    gc.collectGarbage();

    MPointerGC::getInstance().debug();
}

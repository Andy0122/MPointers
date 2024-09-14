#include <gtest/gtest.h>
#include "MPointer.h"

// Prueba de creación de MPointer
TEST(MPointerTest, CreateMPointer) {
    MPointer<int> ptr = MPointer<int>::New();
    *ptr = 10;
    EXPECT_EQ(*ptr, 10);
}

// Prueba de que el recolector de basura elimina correctamente
TEST(MPointerTest, PointerDeletion) {
    {
        MPointer<int> temp = MPointer<int>::New();
        *temp = 20;
        EXPECT_EQ(*temp, 20);
    }
    // El MPointer debe ser eliminado al salir del ámbito
    MPointerGC::getInstance().collectGarbage();
}

// Prueba del operador de asignación
TEST(MPointerTest, AssignmentOperator) {
    MPointer<int> ptr1 = MPointer<int>::New();
    *ptr1 = 100;

    MPointer<int> ptr2 = MPointer<int>::New();
    ptr2 = ptr1;

    EXPECT_EQ(*ptr2, 100);
}

// Prueba de la sobrecarga del operador de asignación para valores
TEST(MPointerTest, AssignValue) {
    MPointer<int> ptr = MPointer<int>::New();
    ptr = 50;
    EXPECT_EQ(*ptr, 50);
}

#include <gtest/gtest.h>
#include "DoublyLinkedList.h"

// Prueba de la creación de una lista doblemente enlazada
TEST(DoublyLinkedListTest, CreateList) {
    DoublyLinkedList<int> list;
    EXPECT_EQ(list.size(), 0);
}

// Prueba de inserción de elementos
TEST(DoublyLinkedListTest, AppendElements) {
    DoublyLinkedList<int> list;
    list.append(10);
    list.append(20);
    list.append(30);

    EXPECT_EQ(list.size(), 3);
    EXPECT_EQ(list.getAt(0), 10);
    EXPECT_EQ(list.getAt(1), 20);
    EXPECT_EQ(list.getAt(2), 30);
}

// Prueba de inserción en una posición específica
TEST(DoublyLinkedListTest, InsertAt) {
    DoublyLinkedList<int> list;
    list.append(10);
    list.append(30);
    list.insertAt(20, 1);

    EXPECT_EQ(list.getAt(1), 20);
}

// Prueba de intercambio de nodos
TEST(DoublyLinkedListTest, SwapNodes) {
    DoublyLinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.swap(0, 2);

    EXPECT_EQ(list.getAt(0), 3);
    EXPECT_EQ(list.getAt(2), 1);
}


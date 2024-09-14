#include <gtest/gtest.h>
#include "SortingAlgrithms.h"
#include "DoublyLinkedList.h"

// Prueba de Bubble Sort
TEST(SortingTest, BubbleSort) {
    DoublyLinkedList<int> list;
    list.append(3);
    list.append(1);
    list.append(4);
    list.append(2);

    bubbleSort(list);

    EXPECT_EQ(list.getAt(0), 1);
    EXPECT_EQ(list.getAt(1), 2);
    EXPECT_EQ(list.getAt(2), 3);
    EXPECT_EQ(list.getAt(3), 4);
}

// Prueba de Quick Sort
TEST(SortingTest, QuickSort) {
    DoublyLinkedList<int> list;
    list.append(10);
    list.append(7);
    list.append(8);
    list.append(9);
    list.append(1);
    list.append(5);

    quickSort(list, 0, list.size() - 1);

    EXPECT_EQ(list.getAt(0), 1);
    EXPECT_EQ(list.getAt(1), 5);
    EXPECT_EQ(list.getAt(2), 7);
    EXPECT_EQ(list.getAt(3), 8);
    EXPECT_EQ(list.getAt(4), 9);
    EXPECT_EQ(list.getAt(5), 10);
}

// Prueba de Insertion Sort
TEST(SortingTest, InsertionSort) {
    DoublyLinkedList<int> list;
    list.append(12);
    list.append(11);
    list.append(13);
    list.append(5);
    list.append(6);

    insertionSort(list);

    EXPECT_EQ(list.getAt(0), 5);
    EXPECT_EQ(list.getAt(1), 6);
    EXPECT_EQ(list.getAt(2), 11);
    EXPECT_EQ(list.getAt(3), 12);
    EXPECT_EQ(list.getAt(4), 13);
}

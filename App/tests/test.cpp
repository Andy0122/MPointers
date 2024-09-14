#include <gtest/gtest.h>


// MPointer tests
TEST(MPointerTest, CreateMPointer) { /* ... */ }
TEST(MPointerTest, PointerDeletion) { /* ... */ }
TEST(MPointerTest, AssignmentOperator) { /* ... */ }
TEST(MPointerTest, AssignValue) { /* ... */ }

// DoublyLinkedList tests
TEST(DoublyLinkedListTest, CreateList) { /* ... */ }
TEST(DoublyLinkedListTest, AppendElements) { /* ... */ }
TEST(DoublyLinkedListTest, InsertAt) { /* ... */ }
TEST(DoublyLinkedListTest, SwapNodes) { /* ... */ }

// Sorting tests
TEST(SortingTest, BubbleSort) { /* ... */ }
TEST(SortingTest, QuickSort) { /* ... */ }
TEST(SortingTest, InsertionSort) { /* ... */ }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
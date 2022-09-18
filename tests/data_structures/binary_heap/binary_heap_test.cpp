#include <gtest/gtest.h>
#include <data_structures/binary_heap/binary_heap.hpp>

TEST(binary_heap_test, get_parent_with_different_use_cases) {
  std::vector v{5, 10, 15, 20};
  BinrayHeap heap(v);
  EXPECT_EQ(heap.parent(0), std::numeric_limits<int>::min());
  EXPECT_EQ(heap.parent(1), 5);
  EXPECT_EQ(heap.parent(2), 5);
  EXPECT_EQ(heap.parent(3), 10);
  EXPECT_EQ(heap.parent(-4), std::numeric_limits<int>::min());
}

TEST(binary_heap_test, get_left_child_with_even_length_vector) {
  std::vector v{5, 10, 15, 20, 25, 30};
  BinrayHeap heap(v);
  EXPECT_EQ(heap.left_child(-5), std::numeric_limits<int>::min());
  EXPECT_EQ(heap.left_child(0), 10);
  EXPECT_EQ(heap.left_child(1), 20);
  EXPECT_EQ(heap.left_child(2), 30);
}

TEST(binary_heap_test, get_left_child_with_odd_length_vector) {
  std::vector v{5, 10, 15, 20, 25, 30, 35};
  BinrayHeap heap(v);
  EXPECT_EQ(heap.left_child(-5), std::numeric_limits<int>::min());
  EXPECT_EQ(heap.left_child(0), 10);
  EXPECT_EQ(heap.left_child(1), 20);
  EXPECT_EQ(heap.left_child(2), 30);
}

TEST(binary_heap_test, get_right_child_with_even_length_vector) {
  std::vector v{5, 10, 15, 20, 25, 30};
  BinrayHeap heap(v);
  EXPECT_EQ(heap.right_child(-42), std::numeric_limits<int>::min());
  EXPECT_EQ(heap.right_child(0), 15);
  EXPECT_EQ(heap.right_child(1), 25);
  EXPECT_EQ(heap.right_child(2), std::numeric_limits<int>::min());
}

TEST(binary_heap_test, get_right_child_with_odd_length_vector) {
  std::vector v{5, 10, 15, 20, 25, 30, 35};
  BinrayHeap heap(v);
  EXPECT_EQ(heap.right_child(-42), std::numeric_limits<int>::min());
  EXPECT_EQ(heap.right_child(0), 15);
  EXPECT_EQ(heap.right_child(1), 25);
  EXPECT_EQ(heap.right_child(2), 35);
}

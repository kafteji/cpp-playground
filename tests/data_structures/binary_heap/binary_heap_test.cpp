#include "data_structures/binary_heap/binary_heap.hpp"
#include <gtest/gtest.h>
#include <algorithm>
#include <vector>

TEST(binary_heap_test, get_parent_with_different_use_cases) {
  std::vector<int> v{5, 10, 15, 20};
  BinrayHeap heap;
  EXPECT_EQ(heap.parent(v.begin(), v.end(), 0),
            std::numeric_limits<int>::min());
  EXPECT_EQ(heap.parent(v.begin(), v.end(), 1), 5);
  EXPECT_EQ(heap.parent(v.begin(), v.end(), 2), 5);
  EXPECT_EQ(heap.parent(v.begin(), v.end(), 3), 10);
  EXPECT_EQ(heap.parent(v.begin(), v.end(), -4),
            std::numeric_limits<int>::min());
}

TEST(binary_heap_test, get_left_child_with_even_length_vector) {
  std::vector<int> v{5, 10, 15, 20, 25, 30};
  BinrayHeap heap;
  EXPECT_EQ(heap.left_child(v.begin(), v.end(), -5),
            std::numeric_limits<int>::min());
  EXPECT_EQ(heap.left_child(v.begin(), v.end(), 0), 10);
  EXPECT_EQ(heap.left_child(v.begin(), v.end(), 1), 20);
  EXPECT_EQ(heap.left_child(v.begin(), v.end(), 2), 30);
}

TEST(binary_heap_test, get_left_child_with_odd_length_vector) {
  std::vector<int> v{5, 10, 15, 20, 25, 30, 35};
  BinrayHeap heap;
  EXPECT_EQ(heap.left_child(v.begin(), v.end(), -5),
            std::numeric_limits<int>::min());
  EXPECT_EQ(heap.left_child(v.begin(), v.end(), 0), 10);
  EXPECT_EQ(heap.left_child(v.begin(), v.end(), 1), 20);
  EXPECT_EQ(heap.left_child(v.begin(), v.end(), 2), 30);
}

TEST(binary_heap_test, get_right_child_with_even_length_vector) {
  std::vector<int> v{5, 10, 15, 20, 25, 30};
  BinrayHeap heap;
  EXPECT_EQ(heap.right_child(v.begin(), v.end(), -42),
            std::numeric_limits<int>::min());
  EXPECT_EQ(heap.right_child(v.begin(), v.end(), 0), 15);
  EXPECT_EQ(heap.right_child(v.begin(), v.end(), 1), 25);
  EXPECT_EQ(heap.right_child(v.begin(), v.end(), 2),
            std::numeric_limits<int>::min());
}

TEST(binary_heap_test, get_right_child_with_odd_length_vector) {
  std::vector<int> v{5, 10, 15, 20, 25, 30, 35};
  BinrayHeap heap;
  EXPECT_EQ(heap.right_child(v.begin(), v.end(), -42),
            std::numeric_limits<int>::min());
  EXPECT_EQ(heap.right_child(v.begin(), v.end(), 0), 15);
  EXPECT_EQ(heap.right_child(v.begin(), v.end(), 1), 25);
  EXPECT_EQ(heap.right_child(v.begin(), v.end(), 2), 35);
}

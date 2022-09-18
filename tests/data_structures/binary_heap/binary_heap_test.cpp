#include "data_structures/binary_heap/binary_heap.hpp"
#include <gtest/gtest.h>
#include <algorithm>
#include <vector>

TEST(binary_heap_test, get_parent_with_different_use_cases) {
  std::vector<int> v{5, 10, 15, 20};
  BinrayHeap heap;
  EXPECT_EQ(heap.get_parent(v.begin(), v.end(), 0), v.end());
  EXPECT_EQ(*heap.get_parent(v.begin(), v.end(), 1), 5);
  EXPECT_EQ(*heap.get_parent(v.begin(), v.end(), 2), 5);
  EXPECT_EQ(*heap.get_parent(v.begin(), v.end(), 3), 10);
  EXPECT_EQ(heap.get_parent(v.begin(), v.end(), -4), v.end());
}

TEST(binary_heap_test, get_left_child_with_even_length_vector) {
  std::vector<int> v{5, 10, 15, 20, 25, 30};
  BinrayHeap heap;
  EXPECT_EQ(heap.get_left_child(v.begin(), v.end(), -5), v.end());
  EXPECT_EQ(*heap.get_left_child(v.begin(), v.end(), 0), 10);
  EXPECT_EQ(*heap.get_left_child(v.begin(), v.end(), 1), 20);
  EXPECT_EQ(*heap.get_left_child(v.begin(), v.end(), 2), 30);
}

TEST(binary_heap_test, get_left_child_with_odd_length_vector) {
  std::vector<int> v{5, 10, 15, 20, 25, 30, 35};
  BinrayHeap heap;
  EXPECT_EQ(heap.get_left_child(v.begin(), v.end(), -5), v.end());
  EXPECT_EQ(*heap.get_left_child(v.begin(), v.end(), 0), 10);
  EXPECT_EQ(*heap.get_left_child(v.begin(), v.end(), 1), 20);
  EXPECT_EQ(*heap.get_left_child(v.begin(), v.end(), 2), 30);
}

TEST(binary_heap_test, get_right_child_with_even_length_vector) {
  std::vector<int> v{5, 10, 15, 20, 25, 30};
  BinrayHeap heap;
  EXPECT_EQ(heap.get_right_child(v.begin(), v.end(), -42), v.end());
  EXPECT_EQ(*heap.get_right_child(v.begin(), v.end(), 0), 15);
  EXPECT_EQ(*heap.get_right_child(v.begin(), v.end(), 1), 25);
  EXPECT_EQ(heap.get_right_child(v.begin(), v.end(), 2), v.end());
}

TEST(binary_heap_test, get_right_child_with_odd_length_vector) {
  std::vector<int> v{5, 10, 15, 20, 25, 30, 35};
  BinrayHeap heap;
  EXPECT_EQ(heap.get_right_child(v.begin(), v.end(), -42), v.end());
  EXPECT_EQ(*heap.get_right_child(v.begin(), v.end(), 0), 15);
  EXPECT_EQ(*heap.get_right_child(v.begin(), v.end(), 1), 25);
  EXPECT_EQ(*heap.get_right_child(v.begin(), v.end(), 2), 35);
}

TEST(binary_heap_test, max_heapify_a_heap_with_two_nodes) {
  std::vector<int> v{10, 50};
  BinrayHeap heap;
  heap.max_heapify(v.begin(), v.end(), 0);
  std::vector<int> expected_result{50, 10};
  EXPECT_TRUE(std::equal(v.begin(), v.end(), expected_result.begin()));
}

TEST(binary_heap_test, max_heapify_a_3_node_heap) {
  std::vector<int> v{5, 10, 15, 20, 25, 30, 35};
  BinrayHeap heap;
  auto end = std::next(v.begin(), 3);
  heap.max_heapify(v.begin(), end, 0);
  std::vector<int> expected_result{15, 10, 5};
  EXPECT_TRUE(std::equal(v.begin(), end, expected_result.begin()));
}

TEST(binary_heap_test, max_heapify_a_leaf_node) {
  std::vector<int> v{5};
  BinrayHeap heap;
  heap.max_heapify(v.begin(), v.end(), 0);
  std::vector<int> expected_result{5};
  EXPECT_TRUE(std::equal(v.begin(), v.end(), expected_result.begin()));
}

TEST(binary_heap_test, max_heapify_a_sub_heap) {
  std::vector<int> v{5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70};
  BinrayHeap heap;
  heap.max_heapify(v.begin(), v.end(), 2);
  std::vector<int> expected_result{5,  10, 35, 20, 25, 30, 70,
                                   40, 45, 50, 55, 60, 65, 15};
  EXPECT_TRUE(std::equal(v.begin(), v.end(), expected_result.begin()));
}

#include "algorithms/sorting/heap_sort.hpp"
#include <gtest/gtest.h>

TEST(heap_sort_test, sort_empty_array) {
  HeapSort heap_sort;
  std::vector<int> v{}, expected_result{};
  heap_sort.sort(v.begin(), v.end());
  EXPECT_TRUE(std::equal(v.begin(), v.end(), expected_result.begin()));
}

TEST(heap_sort_test, sort_one_element_array) {
  HeapSort heap_sort;
  std::vector<int> v{42}, expected_result{42};
  heap_sort.sort(v.begin(), v.end());
  EXPECT_TRUE(std::equal(v.begin(), v.end(), expected_result.begin()));
}

TEST(heap_sort_test, sort_two_element_array) {
  HeapSort heap_sort;
  std::vector<int> v{100, 42}, expected_result{42, 100};
  heap_sort.sort(v.begin(), v.end());
  EXPECT_TRUE(std::equal(v.begin(), v.end(), expected_result.begin()));
}

TEST(heap_sort_test, sort_three_element_array) {
  HeapSort heap_sort;
  std::vector<int> v{5, 2, 3}, expected_result{2, 3, 5};
  heap_sort.sort(v.begin(), v.end());
  EXPECT_TRUE(std::equal(v.begin(), v.end(), expected_result.begin()));
}

TEST(heap_sort_test, sort_random_array) {
  HeapSort heap_sort;
  std::vector<int> v{765, 35, 92782763, 208382, 3145165, 6515};
  std::vector<int> expected_result{35, 765, 6515, 208382, 3145165, 92782763};
  heap_sort.sort(v.begin(), v.end());
  EXPECT_TRUE(std::equal(v.begin(), v.end(), expected_result.begin()));
}
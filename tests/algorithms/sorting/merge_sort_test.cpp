#include "algorithms/sorting/merge_sort.hpp"
#include <gtest/gtest.h>

TEST(merge_sort_test, sort_empty_array) {
  std::vector<int> v{};
  MergeSort sorter;
  sorter.sort(v.begin(), v.end());
  EXPECT_EQ(v, std::vector<int>{});
}

TEST(merge_sort_test, sort_one_element_vector) {
  std::vector<int> v{42};
  MergeSort sorter;
  sorter.sort(v.begin(), v.end());
  EXPECT_EQ(v, std::vector<int>{42});
}

TEST(merge_sort_test, sort_two_element_vector) {
  std::vector<int> v{42, 31};
  MergeSort sorter;
  sorter.sort(v.begin(), v.end());
  EXPECT_EQ(v, std::vector<int>({31, 42}));
}

TEST(merge_sort_test, sort_reverse_sorted_elements) {
  std::vector<int> v{90, 80, 70, 70, 60, 50, 40, 10};
  MergeSort sorter;
  sorter.sort(v.begin(), v.end());
  EXPECT_EQ(v, std::vector<int>({10, 40, 50, 60, 70, 70, 80, 90}));
}

TEST(merge_sort_test, sort_already_sorted_elements) {
  std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
  MergeSort sorter;
  sorter.sort(v.begin(), v.end());
  EXPECT_EQ(v, std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}));
}

TEST(merge_sort_test, sort_random_array) {
  std::vector<int> v{359,     478,       23548, 13456, 654,
                     1236548, 215487965, 12,    35,    89};
  MergeSort sorter;
  sorter.sort(v.begin(), v.end());
  EXPECT_EQ(v, std::vector<int>({12, 35, 89, 359, 478, 654, 13456, 23548,
                                 1236548, 215487965}));
}

TEST(merge_sort_test, sort_only_a_Range_in_array) {
  std::vector<int> v{90, 80, 70, 70, 60, 50, 40, 10};
  MergeSort sorter;
  sorter.sort(v.begin(), std::next(v.begin(), 4));
  EXPECT_EQ(v, std::vector<int>({70, 70, 80, 90, 60, 50, 40, 10}));
}
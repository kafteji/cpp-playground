#include "algorithms/sorting/insertion_sort.hpp"
#include <gtest/gtest.h>

TEST(insertion_sort_test, sort_empty_array) {
  std::vector<int> v{};
  InsertionSort sorter;
  sorter.sort(v);
  EXPECT_EQ(v, std::vector<int>{});
}

TEST(insertion_sort_test, sort_one_element_vector) {
  std::vector<int> v{42};
  InsertionSort sorter;
  sorter.sort(v);
  EXPECT_EQ(v, std::vector<int>{42});
}

TEST(insertion_sort_test, sort_two_element_vector) {
  std::vector<int> v{42, 31};
  InsertionSort sorter;
  sorter.sort(v);
  EXPECT_EQ(v, std::vector<int>({31, 42}));
}

TEST(insertion_sort_test, sort_reverse_sorted_elements) {
  std::vector<int> v{90, 80, 70, 70, 60, 50, 40, 10};
  InsertionSort sorter;
  sorter.sort(v);
  EXPECT_EQ(v, std::vector<int>({10, 40, 50, 60, 70, 70, 80, 90}));
}

TEST(insertion_sort_test, sort_already_sorted_elements) {
  std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
  InsertionSort sorter;
  sorter.sort(v);
  EXPECT_EQ(v, std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}));
}

TEST(insertion_sort_test, sort_random_array) {
  std::vector<int> v{359,     478,       23548, 13456, 654,
                     1236548, 215487965, 12,    35,    89};
  InsertionSort sorter;
  sorter.sort(v);
  EXPECT_EQ(v, std::vector<int>({12, 35, 89, 359, 478, 654, 13456, 23548,
                                 1236548, 215487965}));
}

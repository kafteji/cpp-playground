#include <gtest/gtest.h>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <vector>

class MergeSort {
 public:
  void sort(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (std::distance(begin, end) <= 1) {
      return;
    }
    auto past_mid_point =
        std::next(begin + std::distance(begin, std::prev(end)) / 2);
    sort(begin, past_mid_point);
    sort(past_mid_point, end);
    merge(begin, past_mid_point, past_mid_point, end);
  }

 private:
  void merge(std::vector<int>::iterator left_begin,
             std::vector<int>::iterator left_end,
             std::vector<int>::iterator right_begin,
             std::vector<int>::iterator right_end) {
    auto temp_vector = std::vector<int>(std::distance(left_begin, right_end));
    auto right_cursor = right_begin;
    auto left_cursor = left_begin;
    auto dest_cursor = temp_vector.begin();
    while (right_cursor != right_end and left_cursor != left_end) {
      if (*left_cursor <= *right_cursor) {
        *dest_cursor = *left_cursor;
        std::advance(left_cursor, 1);
      } else {
        *dest_cursor = *right_cursor;
        std::advance(right_cursor, 1);
      }
      std::advance(dest_cursor, 1);
    }
    std::copy(left_cursor, left_end, dest_cursor);
    std::copy(right_cursor, right_end, dest_cursor);
    std::copy(temp_vector.begin(), temp_vector.end(), left_begin);
  }
};

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
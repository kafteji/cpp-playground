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

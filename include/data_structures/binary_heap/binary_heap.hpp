#include <iterator>
#include <limits>
#include <vector>

class BinrayHeap {
 public:
  void max_heapify(std::vector<int>::iterator begin,
                   std::vector<int>::iterator end,
                   int index) {}

  int parent(std::vector<int>::iterator begin,
             std::vector<int>::iterator end,
             int index) {
    if ((index <= 0) or (index >= std::distance(begin, end))) {
      return std::numeric_limits<int>::min();
    }
    // Special case when the index == 2 the parent will be 1 which is wrong
    if (index == 2)
      --index;

    return *std::next(begin, index / 2);
  }

  int left_child(std::vector<int>::iterator begin,
                 std::vector<int>::iterator end,
                 int index) {
    if ((index < 0) or (index >= std::distance(begin, end) / 2)) {
      return std::numeric_limits<int>::min();
    }
    return *std::next(begin, index * 2 + 1);  // +1 since the Heap is zero-based
  }

  int right_child(std::vector<int>::iterator begin,
                  std::vector<int>::iterator end,
                  int index) {
    if ((index < 0) or (index >= std::distance(begin, end) / 2)) {
      return std::numeric_limits<int>::min();
    }
    auto child_index = index * 2 + 2;  // +1 since the Heap is zero-based
    if (child_index >= std::distance(begin, end))
      return std::numeric_limits<int>::min();

    return *std::next(begin, child_index);
  }
};

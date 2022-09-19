#include <algorithm>
#include <iterator>
#include <vector>

class BinrayHeap {
 public:
  void build_max_heap(std::vector<int>::iterator begin,
                      std::vector<int>::iterator end) {
    auto last_parent_index = (std::distance(begin, end) / 2) - 1;
    for (auto i = last_parent_index; i >= 0; --i)
      max_heapify(begin, end, i);
  }
  void max_heapify(std::vector<int>::iterator begin,
                   std::vector<int>::iterator end,
                   int index) {
    auto node = std::next(begin, index);
    auto left_child = get_left_child(begin, end, index);
    auto right_child = get_right_child(begin, end, index);
    auto max_node = node;

    if ((left_child != end) and (*left_child > *node))
      max_node = left_child;

    if ((right_child != end) and (*right_child > *node))
      max_node = right_child;

    if (max_node != node) {
      std::iter_swap(node, max_node);
      max_heapify(begin, end, std::distance(begin, max_node));
    }
  }

  auto get_parent(std::vector<int>::iterator begin,
                  std::vector<int>::iterator end,
                  int index) -> std::vector<int>::iterator {
    if ((index <= 0) or (index >= std::distance(begin, end))) {
      return end;
    }
    // Special case when the index == 2, the parent will be 1 which is wrong
    if (index == 2)
      --index;

    return std::next(begin, index / 2);
  }

  auto get_left_child(std::vector<int>::iterator begin,
                      std::vector<int>::iterator end,
                      int index) -> std::vector<int>::iterator {
    if ((index < 0) or (index >= std::distance(begin, end) / 2)) {
      return end;
    }
    return std::next(begin, index * 2 + 1);  // +1 since the Heap is zero-based
  }

  auto get_right_child(std::vector<int>::iterator begin,
                       std::vector<int>::iterator end,
                       int index) -> std::vector<int>::iterator {
    if ((index < 0) or (index >= std::distance(begin, end) / 2)) {
      return end;
    }
    auto child_index = index * 2 + 2;  // +1 since the Heap is zero-based
    if (child_index >= std::distance(begin, end))
      return end;

    return std::next(begin, child_index);
  }
};

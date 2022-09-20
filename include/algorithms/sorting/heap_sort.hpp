#include <vector>
#include "data_structures/binary_heap/binary_heap.hpp"

class HeapSort {
 public:
  void sort(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    BinrayHeap heap;
    heap.build_max_heap(begin, end);
    while (std::distance(begin, end) >= 2) {
      std::advance(end, -1);
      std::iter_swap(begin, end);
      heap.build_max_heap(begin, end);
    }
  }
};

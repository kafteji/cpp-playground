#include <memory>
#include <vector>

class BinrayHeap {
 public:
  BinrayHeap() = default;

  ~BinrayHeap() noexcept = default;

  BinrayHeap(const std::vector<int>& input) : _heap(input) {}

  int parent(int node) {
    if ((node <= 0) or (node >= _heap.size())) {
      return -1;
    }
    // Special case when the index == 2 the parent will be 1 which is wrong
    if (node == 2)
      --node;

    return _heap[node / 2];
  }

  int left_child(int node) {
    if ((node < 0) or (node >= _heap.size() / 2)) {
      return -1;
    }
    auto child = node * 2 + 1;  // +1 since _heap is zero-based
    return _heap[child];
  }

  int right_child(int node) {
    if ((node < 0) or (node >= _heap.size() / 2)) {
      return -1;
    }
    auto child = node * 2 + 2;  // +1 since _heap is zero-based
    return (child < _heap.size()) ? _heap[child] : -1;
  }

 private:
  std::vector<int> _heap;
};

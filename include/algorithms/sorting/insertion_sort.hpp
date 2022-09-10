#include <vector>

class InsertionSort {
 public:
  void sort(std::vector<int>& v) {
    for (auto i = 1; i < v.size(); ++i) {
      auto key = v[i];
      auto j = i - 1;
      while (j >= 0 and v[j] > key) {
        v[j + 1] = v[j];
        --j;
      }
      v[j + 1] = key;
    }
  }
};

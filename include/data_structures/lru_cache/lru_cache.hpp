#include <list>
#include <optional>
#include <unordered_map>
#include <utility>

template <typename T, size_t SIZE>
class lru_cache {
  static_assert(SIZE > 0);

 public:
  lru_cache() noexcept = default;

  ~lru_cache() noexcept = default;

  void put(const T& value) {
    auto elem = _map.find(value);
    if (elem == _map.end()) {
      if (_list.size() == max_size) {
        _map.erase(_list.back());
        _list.pop_back();
      }
      _list.push_front(value);
      _map.insert(std::make_pair(value, _list.begin()));
    } else {
      _list.splice(_list.begin(), _list, elem->second);
    }
  }

  std::optional<T> fetch(const T& value) {
    auto elem = _map.find(value);
    if (elem != _map.end()) {
      _list.splice(_list.begin(), _list, elem->second);
      return _list.front();
    }
    return std::nullopt;
  }

  T front() const noexcept { return _list.front(); }
  T back() const noexcept { return _list.back(); }
  [[nodiscard]] size_t size() const noexcept { return _list.size(); }

 private:
  const size_t max_size = SIZE;
  std::list<T> _list;
  std::unordered_map<T, typename std::list<T>::iterator> _map;
};

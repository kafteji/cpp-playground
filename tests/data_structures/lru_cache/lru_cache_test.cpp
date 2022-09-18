#include <gtest/gtest.h>
#include <data_structures/lru_cache/lru_cache.hpp>

TEST(lru_cache_test, empty_cache) {
  lru_cache<int, 5> cache;
  EXPECT_EQ(cache.fetch(3), std::nullopt);
}

TEST(lru_cache_test, put_fetch) {
  lru_cache<int, 2> cache;
  cache.put(5);
  EXPECT_EQ(cache.front(), 5);
  auto data = cache.fetch(5);
  EXPECT_TRUE(data.has_value());
  EXPECT_EQ(data.value(), 5);
}

TEST(lru_cache_test, add_when_cache_full) {
  lru_cache<int, 3> cache;
  cache.put(1);
  cache.put(2);
  cache.put(3);
  EXPECT_EQ(cache.front(), 3);
  EXPECT_EQ(cache.back(), 1);
  cache.put(4);
  EXPECT_EQ(cache.front(), 4);
  EXPECT_EQ(cache.back(), 2);
}

TEST(lru_cache_test, add_same_element_twice) {
  lru_cache<int, 5> cache;
  cache.put(1);
  cache.put(2);
  cache.put(3);
  EXPECT_EQ(cache.front(), 3);
  cache.put(1);
  EXPECT_EQ(cache.size(), 3);
  EXPECT_EQ(cache.front(), 1);
}

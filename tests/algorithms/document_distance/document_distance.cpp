#include <gtest/gtest.h>
#include <algorithms/document_distance/document_distance.hpp>

TEST(document_distance_test, extract_words_from_document_success) {
  std::string doc =
      "This is a document for testing pupose, and it has commas, numbers like "
      "55 and a full stop.";
  DocumentDistance parser;
  auto result = parser.extract_words_from_document(doc);
  EXPECT_EQ(result.size(), 18);
  EXPECT_EQ("this", result[0]);
  EXPECT_EQ("stop", result[17]);
  std::string doc1 = "This is a Cat";
  result = parser.extract_words_from_document(doc1);
  EXPECT_EQ(result.size(), 4);
  EXPECT_EQ("this", result[0]);
  EXPECT_EQ("cat", result[3]);
}

TEST(document_distance_test, get_word_count_success) {
  std::vector<std::string> words = {"foo", "bar", "baz", "foo", "foo", "baz"};
  DocumentDistance parser;
  auto result = parser.get_word_count(words);
  EXPECT_EQ(3, result["foo"]);
  EXPECT_EQ(2, result["baz"]);
  EXPECT_EQ(1, result["bar"]);
}

TEST(document_distance_test, calculate_document_distance_test_success) {
  std::string doc1 = "This is a cat";
  std::string doc2 = "foo bar baz daz";
  DocumentDistance parser;
  auto angle = parser.calculate_document_distance(doc1, doc2);
  EXPECT_DOUBLE_EQ(1.5708, std::ceil(angle * 10000) / 10000);
}

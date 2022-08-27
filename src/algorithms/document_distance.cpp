#include <cctype>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

#include <gtest/gtest.h>

class DocumentDistance {
 public:
  auto extract_words_from_document(const std::string& doc)
      -> std::vector<std::string> {
    std::vector<std::string> words = {};
    std::string buffer = {};
    for (auto i = doc.begin(); i != doc.end(); ++i) {
      if (not std::isalnum(*i) and not buffer.empty()) {
        words.push_back(buffer);
        buffer.clear();
        continue;
      }
      buffer.push_back(*i);
    }
    return words;
  }

  auto get_word_count(const std::vector<std::string>& words)
      -> std::unordered_map<std::string, size_t> {
    auto word_count = std::unordered_map<std::string, size_t>{};
    for (const auto& elem : words) {
      word_count[elem]++;
    }
    return word_count;
  }

  double document_distance(const std::string& doc1, const std::string& doc2) {
    auto words_doc1 = extract_words_from_document(doc1);
    auto words_doc2 = extract_words_from_document(doc2);
    return 0;
  }
};

TEST(document_distance_test, extract_words_from_document_success) {
  std::string doc =
      "This is a document for testing pupose, and it has commas, numbers like "
      "55 and a full stop.";
  DocumentDistance parser;
  auto result = parser.extract_words_from_document(doc);
  EXPECT_EQ(result.size(), 18);
  EXPECT_EQ("This", result[0]);
  EXPECT_EQ("stop", result[17]);
}

TEST(document_distance_test, get_word_count_success) {
  std::vector<std::string> words = {"foo", "bar", "baz", "foo", "foo", "baz"};
  DocumentDistance parser;
  auto result = parser.get_word_count(words);
  EXPECT_EQ(3, result["foo"]);
  EXPECT_EQ(2, result["baz"]);
  EXPECT_EQ(1, result["bar"]);
}
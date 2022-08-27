#include <cctype>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

#include <gtest/gtest.h>

class DocumentDistance {
 public:
  std::vector<std::string> extract_words_from_document(const std::string& doc) {
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

  double document_distance(const std::string& doc1, const std::string& doc2) {
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
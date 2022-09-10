/*
  Dataset used in this program:
  t2.bobsey.txt ->
  https://ocw.mit.edu/ans7870/6/6.006/s08/lecturenotes/files/t2.bobsey.txt
  t3.lewis.txt  ->
  https://ocw.mit.edu/ans7870/6/6.006/s08/lecturenotes/files/t3.lewis.txt
*/

#include <cctype>
#include <cmath>
#include <fstream>
#include <numeric>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

class DocumentDistance {
 public:
  auto load_dataset(const std::string& dataset_name) -> std::string {
    auto file = std::ifstream{dataset_name};
    std::stringstream buffer{};
    buffer << file.rdbuf();
    return buffer.str();
  }

  auto extract_words_from_document(const std::string& doc)
      -> std::vector<std::string> {
    std::vector<std::string> words = {};
    std::string buffer = {};
    for (auto i = doc.begin(); i != doc.end(); ++i) {
      if (std::isalnum(*i)) {
        buffer.push_back(std::tolower(*i));

      } else if (not buffer.empty()) {
        words.push_back(buffer);
        buffer.clear();
        continue;
      }
    }
    if (not buffer.empty()) {
      words.push_back(buffer);
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

  auto get_document_norm(
      const std::unordered_map<std::string, size_t>& word_count) -> double {
    auto sum_of_squares = std::accumulate(
        word_count.begin(), word_count.end(), 0,
        [](auto acc, auto x) { return acc + std::pow(x.second, 2); });
    return std::sqrt(sum_of_squares);
  }

  double calculate_document_distance(const std::string& doc1,
                                     const std::string& doc2) {
    auto words_doc1 = extract_words_from_document(doc1);
    auto word_count_doc_1 = get_word_count(words_doc1);
    auto words_doc2 = extract_words_from_document(doc2);
    auto word_count_doc_2 = get_word_count(words_doc2);
    auto [short_doc, long_doc] =
        (word_count_doc_1.size() > word_count_doc_2.size())
            ? std::make_tuple(word_count_doc_2, word_count_doc_1)
            : std::make_tuple(word_count_doc_1, word_count_doc_2);
    auto inner_product = 0;
    for (auto itr = short_doc.begin(); itr != short_doc.end(); ++itr) {
      inner_product +=
          itr->second *
          ((long_doc.contains(itr->first)) ? long_doc.at(itr->first) : 0);
    }
    return std::acos(inner_product / (get_document_norm(word_count_doc_1) *
                                      get_document_norm(word_count_doc_2)));
  }
};

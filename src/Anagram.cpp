#include <iostream>
#include <string>
#include <unordered_map>

void printMap(const std::unordered_map<char, int>& map) {
  for (auto& it : map) {
    std::cout << it.first << ": " << it.second << std::endl;
  }
}

class Solution {
 public:
  bool isAnagram(std::string s, std::string t) {
    if (s.length() != t.length()) {
      return false;
    }

    auto sCounts = buildMap(s);
    auto tCounts = buildMap(t);

    for (auto& c : sCounts) {
      if (tCounts[c.first] != c.second) {
        return false;
      }
    }

    return true;
  }

 private:
  std::unordered_map<char, int> buildMap(std::string word) {
    std::unordered_map<char, int> counts;

    for (char c : word) {
      if (counts.find(c) == counts.end()) {
        counts[c] = 1;
      } else {
        counts[c]++;
      }
    }

    return counts;
  }
};

int main() {
  std::string s = "aacc";
  std::string t = "ccac";

  Solution sol;

  bool result = sol.isAnagram(s, t);

  std::cout << "Is anagram: " << result << std::endl;
}
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

template <class T>
void printVec(const vector<T> vec) {
  for (auto el : vec) {
    std::cout << el << " ";
  }

  std::cout << std::endl;
}

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagrams;

    for (auto s : strs) {
      vector<int> counts(26, 0);
      for (auto c : s) {
        counts[int(c) - int('a')]++;
      }

      std::string key(counts.begin(), counts.end());

      if (anagrams.find(key) == anagrams.end()) {
        anagrams[key] = vector<string>({s});
      } else {
        anagrams[key].push_back(s);
      }
    }

    vector<vector<string>> result = {};
    for (auto& it : anagrams) {
      result.push_back(it.second);
    }

    return result;
  }
};

int main() {
  vector<string> words{"eat", "tea", "tan", "ate", "nat", "bat"};

  Solution sol;

  auto result = sol.groupAnagrams(words);

  for (auto& vec : result) {
    printVec(vec);
  }
}
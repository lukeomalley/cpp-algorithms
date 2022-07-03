#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

// Given an integer array nums and an integer k, return the k most frequent
// elements. You may return the answer in any order.
class Solution {
 public:
  std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
    std::unordered_map<int, int> counts = {};
    std::vector<int> result;
    result.reserve(nums.size());

    for (auto n : nums) {
      if (1 == ++counts[n]) {
        result.push_back(n);
      }
    }

    // Partial sorting algorithm that rearranges elements in [first, last] such
    // that the element pointed at by by nth is changed to whatever element
    // could occur in that position if [first, last] were sorted to that
    // position. All of the elements before this new nth element are less than
    // or equal to the elements after the new nth element.
    std::nth_element(
        result.begin(), result.begin() + k - 1, result.end(),
        [&counts](int l, int r) -> bool { return counts[l] > counts[r]; });

    result.resize(k);

    return result;
  }
};

int main() {
  std::vector<int> nums = {1, 1, 1, 1, 2, 3, 4, 4};

  int k = 2;

  Solution s;

  std::vector<int> res = s.topKFrequent(nums, k);

  for (int i = 0; i < res.size(); i++) {
    std::cout << res[i] << " ";
  }

  std::cout << std::endl;

  return 0;
}

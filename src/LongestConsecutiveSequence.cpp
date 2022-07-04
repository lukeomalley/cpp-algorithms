#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

/**
 * Given an unsorted array of integers nums, return the length of the longest
 * consecutive elements sequence.
 *
 * You must write an algorithm that runs in O(n) time.
 */
class Solution {
 public:
  int longestConsecutive(std::vector<int>& nums) {
    std::unordered_set<int> set(nums.begin(), nums.end());

    int longest = 0;
    for (auto& num : set) {
      // If a number lower than the current number exists in the set, then
      // just continue until we get to the lowest number in the set
      if (set.count(num - 1)) {
        continue;
      }

      // Conut the consecutive numbers
      int count = 1;
      while (set.count(num + count)) {
        count++;
      }
      longest = std::max(longest, count);
    }

    return longest;
  }
};

int main() {
  std::vector<int> input = {100, 200, 4, 5, 6, 300, 1, 2, 3, 1, 1, 1};
  Solution sol;
  std::cout << "Longest: " << sol.longestConsecutive(input) << std::endl;
  return 0;
}
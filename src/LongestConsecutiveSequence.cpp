#include <iostream>
#include <vector>

/**
 * Given an unsorted array of integers nums, return the length of the longest
 * consecutive elements sequence.
 *
 * You must write an algorithm that runs in O(n) time.
 */
class Solution {
 public:
  int longestConsecutive(std::vector<int>& nums) {}
};

int main() {
  std::vector<int> input = {100, 200, 4, 300, 1, 2, 3};

  Solution sol;

  std::cout << "Longest: " << sol.longestConsecutive(input) << std::endl;

  return 0;
}
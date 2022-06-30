#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  int countKDifference(std::vector<int>& nums, int k) {
    int count = 0;

    for (int i = 0; i < nums.size(); i++) {
      for (int j = i; j < nums.size(); j++) {
        if (abs(nums[i] - nums[j]) == k) {
          count++;
        }
      }
    }

    return count;
  }
};

int main() {
  std::vector<int> nums = {1, 2, 2, 1};
  int k = 1;

  Solution sol;

  int result = sol.countKDifference(nums, k);

  std::cout << "Result: " << result << std::endl;
}
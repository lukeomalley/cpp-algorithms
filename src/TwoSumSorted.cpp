#include <iostream>
#include <vector>

using namespace std;

/**
 * Given a 1-indexed array of integers numbers that is already sorted in
 * non-decreasing order, find two numbers such that they add up to a specific
 * target number. Let these two numbers be numbers[index1] and numbers[index2]
 * where 1 <= index1 < index2 <= numbers.length.
 *
 * Return the indices of the two numbers, index1 and index2, added by one as an
 * integer array [index1, index2] of length 2.
 *
 * The tests are generated such that there is exactly one solution. You may not
 * use the same element twice.
 *
 * Your solution must use only constant extra space.
 */
class Solution {
 public:
  vector<int> twoSum(vector<int> nums, int target) {
    int lp = 0;
    int rp = nums.size() - 1;

    while (lp < rp) {
      int sum = nums[lp] + nums[rp];

      if (sum == target) {
        break;
      }

      if (sum > target) {
        rp--;
      } else {
        lp++;
      }
    }

    return {lp + 1, rp + 1};
  }
};

int main() {
  Solution sol;

  vector<int> nums = {1, 3, 4, 5, 7, 10, 11};

  vector<int> result = sol.twoSum(nums, 9);

  std::cout << "Result: " << result[0] << ", " << result[1] << std::endl;
}
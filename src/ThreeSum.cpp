#include <algorithm>
#include <vector>

using namespace std;

/*
  Given an integer array nums, return all the triplets [nums[i], nums[j],
  nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k]
  == 0.

  Notice that the solution set must not contain duplicate triplets.

  @example:
    Input: nums = [-1,0,1,2,-1,-4]
    Output: [[-1,-1,2],[-1,0,1]]
*/
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> result = {};

    // Sort the array of nums
    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
      if (i != 0 && nums[i] == nums[i - 1]) {
        // Skip any duplicates that we've already seen
        continue;
      }

      int lp = i + 1;
      int rp = nums.size() - 1;

      while (lp < rp) {
        int currSum = nums[i] + nums[lp] + nums[rp];
        if (currSum == 0) {
          // Add this result to the set
          result.push_back({nums[i], nums[lp], nums[rp]});
          lp++;
          while (nums[lp] == nums[lp - 1] && lp < rp) {
            lp++;
          }
        } else if (currSum > 0) {
          rp--;
        } else {
          lp++;
        }
      }
    }

    return result;
  };
};

int main() {
  vector<int> nums = {-1, 0, 1, 2, -1, -4};

  Solution Sol;

  auto result = Sol.threeSum(nums);

  return 0;
}

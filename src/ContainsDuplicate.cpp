#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// // Using unordered_set
// bool containsDuplicate(std::vector<int> nums) {
//   return nums.size() !=
//          std::unordered_set<int>(nums.begin(), nums.end()).size();
// }

// Using sort
bool containsDuplicate(std::vector<int> nums) {
  sort(nums.begin(), nums.end());

  for (int i = 0; i < nums.size() - 1; i++) {
    if (nums[i] == nums[i + 1]) {
      return true;
    }
  }

  return false;
}

int main() {
  std::vector<int> duplicate = {1, 2, 1, 4};
  std::vector<int> noDuplicate = {1, 2, 3, 4};

  std::cout << "Contains Duplicates:" << containsDuplicate(duplicate)
            << std::endl;

  std::cout << "Does Not Contains Duplicates:" << containsDuplicate(noDuplicate)
            << std::endl;
}

#include <iostream>
#include <string>
#include <vector>

// Given an integer array nums, return an array answer such that answer[i] is
// equal to the product of all the elements of nums except nums[i]. The product
// of any prefix or suffix of nums is guaranteed to fit in a 32 - bit integer.
// You must write an algorithm that runs in O(n) time and without using the
// division operation.

// input: [1, 2, 3]
// output: [6, 3, 2]

class Solution {
public:
  std::vector<int> productExceptSelf(std::vector<int> &nums) {
    int n = nums.size();
    std::vector<int> lp(n);
    std::vector<int> rp(n);
    std::vector<int> result(n);

    lp[0] = 1;
    for (int i = 1; i < n; i++) {
      lp[i] = lp[i - 1] * nums[i - 1];
    }

    rp[n - 1] = 1;
    for (int j = n - 2; j >= 0; j--) {
      rp[j] = rp[j + 1] * nums[j + 1];
    }

    for (int k = 0; k < n; k++) {
      result[k] = lp[k] * rp[k];
    }

    return result;
  }

  std::vector<int> productExceptSelfOpti(std::vector<int> &nums) {
    int n = nums.size();
    std::vector<int> result(n);

    // Compute the right product and store it in the result array
    result[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
      result[i] = nums[i + 1] * result[i + 1];
    }

    // Compute the left product and store in temp variable during forward
    // iteration
    int lp = 1;
    for (int i = 0; i < n; i++) {
      result[i] = lp * result[i];
      lp = lp * nums[i];
    }

    return result;
  }

private:
  void printVec(std::string prefix, std::vector<int> vec) {

    std::cout << prefix;
    for (auto n : vec) {
      std::cout << n << " ";
    }
    std::cout << std::endl;
  }
};

int main() {
  std::vector<int> nums{1, 2, 3, 4};
  Solution sol;
  sol.productExceptSelfOpti(nums);
  return 0;
}

#include <iostream>
#include <vector>

using namespace std;

// Given an integer array nums and an integer k, return the k most frequent
// elements. You may return the answer in any order.
class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {}
};

int main() {
  vector<int> nums = {1, 1, 1, 2, 2, 3};
  int k = 2;

  Solution s;

  vector<int> res = s.topKFrequent(nums, k);

  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }

  cout << endl;

  return 0;
}
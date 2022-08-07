#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
  11. Container With Most Water

  You are given an integer array height of length n. There are n vertical lines
  drawn such that the two endpoints of the ith line are (i, 0) and (i,
  height[i]).

  Find two lines that together with the x-axis form a container, such that the
  container contains the most water.

  Return the maximum amount of water a container can store.

  Notice that you may not slant the container.

  @example
    Input: height = [1,8,6,2,5,4,8,3,7]
    Output: 49
*/
class Solution {
 public:
  int maxArea(vector<int>& height) {
    // Start with pointers on the outer edges of the height array
    int lp = 0;
    int rp = height.size() - 1;

    int maxArea = 0;
    while (lp < rp) {
      int currArea = min(height[lp], height[rp]) * (rp - lp);
      maxArea = max(maxArea, currArea);

      // Move the pointers in based on which is smaller
      if (height[rp] < height[lp]) {
        rp--;
      } else {
        lp++;
      }
    }

    return maxArea;
  }
};

int main() {
  vector<int> input = {1, 8, 6, 2, 5, 4, 8, 3, 7};

  Solution sol;

  auto result = sol.maxArea(input);

  cout << "Max Area Is: " << result << endl;

  return 0;
}
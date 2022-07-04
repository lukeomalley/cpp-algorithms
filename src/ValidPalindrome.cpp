#include <iostream>
#include <string>

class Solution {
 public:
  bool validPalindrome(std::string s) { return true; }
};

int main() {
  Solution sol;

  std::string input = "racecar";

  std::cout << "Palindrome: " << sol.validPalindrome(input) << std::endl;

  return 0;
}
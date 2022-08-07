#include <algorithm>
#include <iostream>
#include <string>

class Solution {
 public:
  bool isPalindrome(std::string s) {
    int lp = 0;             // Left pinter
    int rp = s.size() - 1;  // Right pointer

    while (lp < rp) {
      while (!isalnum(s[lp]) && lp < rp) {
        lp++;
      }

      while (!isalnum(s[rp]) && lp < rp) {
        rp--;
      }

      if (tolower(s[lp]) != tolower(s[rp])) {
        return false;
      }

      lp++;
      rp--;
    }

    return true;
  }
};

int main() {
  Solution sol;

  std::string input = "A man, a plan, a canal: Panama";

  std::cout << "Palindrome: " << sol.isPalindrome(input) << std::endl;

  return 0;
}
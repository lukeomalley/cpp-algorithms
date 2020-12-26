#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str)
{
  int left = 0;
  int right = str.size() - 1;

  while (left < right)
  {
    if (str[left] != str[right])
    {
      return false;
    }

    left++;
    right--;
  }

  return true;
}

int main()
{
  bool drome = isPalindrome("raceca");

  cout << drome;
}
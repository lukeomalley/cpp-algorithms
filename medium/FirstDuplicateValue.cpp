#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int firstDuplicateValue(vector<int> array)
{
  unordered_map<int, int> numberCounts = {};

  for (int num : array)
  {
    if (numberCounts.find(num) != numberCounts.end())
    {
      return num;
    }

    numberCounts.insert({num, 1});
  }

  return -1;
}

int main()
{
  vector<int> input = {2, 1, 5, 3, 3, 2, 4};

  cout << firstDuplicateValue(input);
}

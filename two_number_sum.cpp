#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum)
{
  for (int i = 0; i < array.size(); i++)
  {
    int firstNum = array[i];
    for (int j = i + 1; j < array.size(); j++)
    {
      int secondNum = array[j];

      if (firstNum + secondNum == targetSum)
      {
        return vector<int>{firstNum, secondNum};
      }
    }
  }

  return {};
}

vector<int> twoNumberWithSort(vector<int> array, int targetSum)
{
  sort(array.begin(), array.end());

  int left = 0;
  int right = array.size() - 1;

  while (left < right)
  {
    int currentSum = array[left] + array[right];
    if (currentSum == targetSum)
    {
      return {array[left], array[right]};
    }
    else if (currentSum > targetSum)
    {
      right--;
    }
    else if (currentSum < targetSum)
    {
      left++;
    }
  }

  return {};
}

vector<int> twoNumberWithSet(vector<int> array, int targetSum)
{
  unordered_set<int> nums;
  for (int num : array)
  {
    int potentialMatch = targetSum - num;
    if (nums.find(potentialMatch) != nums.end())
    {
      return {potentialMatch, num};
    }
    else
    {
      nums.insert(num);
    }
  }

  return {};
}

int main()
{
  vector<int> output = twoNumberWithSet({1, 2, 3, 4, 5, 6}, 9);

  for (int num : output)
  {
    cout << num << endl;
  }
}
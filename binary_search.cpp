#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>, int target);
int binarySearchHelper(vector<int>, int target, int left, int right);

int binarySearch(vector<int> array, int target)
{
  return binarySearchHelper(array, target, 0, array.size() - 1);
}

int binarySearchHelper(vector<int> array, int target, int left, int right)
{
  while (left <= right)
  {
    int middle = (left + right) / 2;
    int potentialMatch = array[middle];

    if (target == potentialMatch)
    {
      return middle;
    }
    else if (target < potentialMatch)
    {
      right = middle - 1;
    }
    else
    {
      left = middle + 1;
    }
  }

  return -1;
}

int main()
{
  cout << binarySearch(vector<int>{1, 2, 3, 4, 5, 6, 7}, 5);
}
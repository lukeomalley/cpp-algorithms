#include <vector>
#include <iostream>

using namespace std;

vector<int> bubbleSort(vector<int> array);

vector<int> bubbleSort(vector<int> array)
{
  if (array.empty())
  {
    return {};
  }

  bool sorted = false;
  int counter = 0;

  while (!sorted)
  {
    sorted = true;
    for (int i = 0; i < array.size() - 1 - counter; i++)
    {
      if (array[i] > array[i + 1])
      {
        swap(array[i], array[i + 1]);
        sorted = false;
      }
    }
    counter++;
  }
  return array;
}

void printVec(vector<int> array)
{
  for (int num : array)
  {
    cout << num << " ";
  }
}

int main()
{
  vector<int> input = {6, 5, 45, 4, 3, 1, 5, 100};

  auto sortedArray = bubbleSort(input);

  printVec(sortedArray);
}

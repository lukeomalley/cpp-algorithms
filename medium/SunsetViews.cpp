#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum Direction
{
  east,
  west
};

void printVec(vector<int> array)
{
  for (int num : array)
  {
    cout << num << " ";
  }
}

vector<int> sunsetViews(vector<int> buildings, Direction direction)
{

  int currentHeight = 0;
  vector<int> canSeeSunset = {};

  switch (direction)
  {
  case east:
    for (int i = buildings.size() - 1; i >= 0; i--)
    {
      int currentBuildingHeight = buildings[i];
      if (currentBuildingHeight > currentHeight)
      {
        currentHeight = currentBuildingHeight;
        canSeeSunset.insert(canSeeSunset.begin(), i);
      }
    }

    return canSeeSunset;
  case west:
    for (int i = 0; i < buildings.size(); i++)
    {
      int currentBuildingHeight = buildings[i];
      if (currentBuildingHeight > currentHeight)
      {
        currentHeight = currentBuildingHeight;
        canSeeSunset.push_back(i);
      }
    }

    return canSeeSunset;
  default:
    return {};
  }
}

vector<int> buildingsWithSunsetViews(vector<int> buildings, string direction)
{
  vector<int> sunsetViews;

  int startIdx = buildings.size() - 1;
  int setp = -1;

  if (direction == "WEST")
  {
    startIdx = 0;
    setp = 1;
  }

  int idx = startIdx;
  int runningMaxHeight = 0;
  while (idx >= 0 && idx < buildings.size())
  {
    int currentBuildingHeight = buildings[idx];

    if (currentBuildingHeight > runningMaxHeight)
    {
      sunsetViews.push_back(idx);
    }

    runningMaxHeight = max(currentBuildingHeight, runningMaxHeight);

    idx += setp;
  }

  if (direction == "EAST")
  {
    reverse(sunsetViews.begin(), sunsetViews.end());
  }

  return sunsetViews;
}

int main()
{
  vector<int> testBuildings = {3, 5, 4, 4, 3, 1, 3, 2};
  Direction testDir = east;

  printVec(buildingsWithSunsetViews(testBuildings, "EAST"));
}
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> nums, int target)
{
  unordered_map<int, int> myMap;

  for (int i = 0; i < nums.size(); i++)
  {
    int diff = target - nums[i];
    if (myMap.count(nums[i]))
    {
      return {myMap[nums[i]], i};
    }
    myMap.insert({diff, i});
  }

  return {};
}

int main()
{
  vector<int> nums = {1, 3, 4, 2, 5};
  int target = 6;

  vector<int> res = twoSum(nums, target);
}
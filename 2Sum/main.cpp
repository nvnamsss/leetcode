#include <vector>
#include <iostream>
#include <map>
using namespace std;

// Given an array of integers, return indices of the two numbers such that they add up to a specific target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// Example:

// Given nums = [2, 7, 11, 15], target = 9,

// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> dictionary = map<int, int>();
        vector<int> r = vector<int>(2);
        r[0] = -1;
        r[1] = -1;

        if (nums.size() > 1)
        {
            dictionary[target - nums[0]] = 0;
            for (int loop = 1; loop < nums.size(); loop++)
            {
                if (dictionary.find(nums[loop]) != dictionary.end())
                {
                    cout << "Get pair [" << nums[loop] << "," << nums[dictionary[nums[loop]]];
                    r[0] = loop;
                    r[1] = dictionary[nums[loop]];
                    return r;
                }

                if (dictionary.find(target - nums[loop]) == dictionary.end())
                {
                    dictionary[target - nums[loop]] = loop;
                }
            }
        }

        return r;
    }
};

int main()
{
    cout << "welcome";
    cin.get();
    //Help!!! I can't build, did I make something wrong?
}
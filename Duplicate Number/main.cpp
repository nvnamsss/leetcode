#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int turtoise = nums[0];
        int hare = nums[0];

        do
        {
            turtoise = nums[turtoise];
            hare = nums[nums[hare]];
        } while (turtoise != hare);

        hare = turtoise;
        turtoise = nums[0];
        while (hare != turtoise)
        {
            turtoise = nums[turtoise];
            hare = nums[hare];
        }

        return turtoise;
    }
};
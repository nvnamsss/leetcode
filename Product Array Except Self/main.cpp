#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        if (nums.size() == 0)
            return vector<int>(0);

        int length = nums.size();
        vector<int> output = vector<int>(length);

        int t = nums[0];
        output[0] = 1;
        for (int loop = 1; loop < length; loop++)
        {
            output[loop] = t;
            t *= nums[loop];
        }

        t = nums[length - 1];
        for (int loop = length - 2; loop >= 0; loop--)
        {
            output[loop] *= t;
            t *= nums[loop];
        }

        return output;
    }
};
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
// Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

// Note: You may not slant the container and n is at least 2.
class Solution
{
public:
    int min(int a, int b)
    {
        if (a < b) return a;
        return b;
    }
    int maxArea(vector<int> &height)
    {
        int length = height.size();
        if (length < 2)
            return 0;
        int w = length;
        int h = height[0];
        int s = 0;
        int e = length - 1;
        int max = 0;

        while (s < e)
        {
            w = e - s;
            h = min(height[s], height[e]);
            if (w * h > max) max = w * h;
            if (height[e] < height[s])
            {
                e -= 1;
            }
            else
            {
                s += 1;
            }
        }

        return max;
    }
};

int main()
{
    Solution s = Solution();
    vector<int> *t1 = new vector<int>();
    // t1.push_back(1);
    // t1.push_back(2);
    // t1.push_back(3);
    // t1.push_back(4);
    // t1.push_back(1);
    // cout << s.maxArea(t1);

    cin.get();
}
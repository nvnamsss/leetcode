#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    queue<int> reef;
    int trap(vector<int> &height)
    {
        int length = height.size();
        int trapped = 0;
        int left = 0;
        int right = length - 1;
        int leftMax = 0;
        int rightMax = 0;
        while (left < right)
        {
            if (height[left] <= height[right])
            {   
                if (height[left] >= leftMax)
                {
                    leftMax = height[left];
                }
                else
                {
                    trapped += leftMax - height[left];
                }
                left++;
            }
            else{
                if (height[right] >= rightMax)
                {
                    rightMax = height[right];
                }
                else{
                    trapped += rightMax - height[right];
                }

                right--;
            }
        }
        // int sure = 0;
        // int estimate = 0;
        // queue<int> qo = queue<int>();
        // reef = queue<int>();
        // for (int loop = 0; loop < length; loop++)
        // {
        //     if (qo.size() == 0 && height[loop] > 0)
        //     {
        //         qo.push(height[loop]);
        //         reef.push(loop);
        //         continue;
        //     }

        //     if (qo.size() > 0 && height[loop] < qo.front())
        //     {
        //         estimate += qo.front() - height[loop];
        //         if (height[loop] > 0)
        //         {
        //             if (reef.size() > 0)
        //             {
        //                 int temp = 0;
        //                 while (height[reef.back()] <= height[loop])
        //                 {
        //                     estimate -= (loop - reef.back() - 1) * height[reef.back()] + temp;
        //                     sure += (loop - reef.back() - 1) * height[reef.back()] - temp;
        //                     temp = height[reef.back()];
        //                     reef.pop();
        //                 }
        //             }

        //             reef.push(loop);
        //         }
        //     }

        //     if (qo.size() > 0 && height[loop] >= qo.front())
        //     {
        //         trapped += estimate + sure;
        //         estimate = 0;
        //         sure = 0;

        //         cout << "trapped: " << trapped << endl;
        //         qo.pop();
        //         qo.push(height[loop]);
        //         while (reef.size() > 0) reef.pop();
        //     }
        // }

        // trapped += sure;

        return trapped;
    }
};

int main()
{
    Solution s = Solution();
    vector<int> t1 = vector<int>();
    t1.push_back(0);
    t1.push_back(1);
    t1.push_back(0);
    t1.push_back(2);
    t1.push_back(1);
    t1.push_back(0);
    t1.push_back(1);
    t1.push_back(3);
    t1.push_back(3);
    t1.push_back(3);
    t1.push_back(3);
    t1.push_back(1);

    cout << s.trap(t1);
    cin.get();
}
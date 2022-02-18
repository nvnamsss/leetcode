/*
Fruits are available at some positions on an infinite x-axis. You are given a 2D integer array fruits where fruits[i] = [positioni, amounti] depicts amounti fruits at the position positioni. fruits is already sorted by positioni in ascending order, and each positioni is unique.

You are also given an integer startPos and an integer k. Initially, you are at the position startPos. From any position, you can either walk to the left or right. It takes one step to move one unit on the x-axis, and you can walk at most k steps in total. For every position you reach, you harvest all the fruits at that position, and the fruits will disappear from that position.

Return the maximum total number of fruits you can harvest.

 

Example 1:


Input: fruits = [[2,8],[6,3],[8,6]], startPos = 5, k = 4
Output: 9
Explanation: 
The optimal way is to:
- Move right to position 6 and harvest 3 fruits
- Move right to position 8 and harvest 6 fruits
You moved 3 steps and harvested 3 + 6 = 9 fruits in total.
Example 2:


Input: fruits = [[0,9],[4,1],[5,7],[6,2],[7,4],[10,9]], startPos = 5, k = 4
Output: 14
Explanation: 
You can move at most k = 4 steps, so you cannot reach position 0 nor 10.
The optimal way is to:
- Harvest the 7 fruits at the starting position 5
- Move left to position 4 and harvest 1 fruit
- Move right to position 6 and harvest 2 fruits
- Move right to position 7 and harvest 4 fruits
You moved 1 + 3 = 4 steps and harvested 7 + 1 + 2 + 4 = 14 fruits in total.
Example 3:


Input: fruits = [[0,3],[6,4],[8,5]], startPos = 3, k = 2
Output: 0
Explanation:
You can move at most k = 2 steps and cannot reach any position with fruits.
 

Constraints:

1 <= fruits.length <= 105
fruits[i].length == 2
0 <= startPos, positioni <= 2 * 105
positioni-1 < positioni for any i > 0 (0-indexed)
1 <= amounti <= 104
0 <= k <= 2 * 105
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int searchL(vector<int>& step, int k) {
        int l = 0;
        int r = step.size() - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if (step[mid] < k) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return max(0, l - 1);
    }

    int searchR(vector<int>& step, int k) {
        int l = 0;
        int r = step.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (step[mid] == k) {
                return mid;
            } 
            else if (step[mid] < k)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return l - 1;
    }
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int ans = 0;
        vector<int> total = vector<int>(fruits.size() + 1);
        vector<int> step = vector<int>(fruits.size() + 1);
        
        int from = 0;
        for (int i = 0; i < fruits.size(); i++)
        {
            total[i + 1] = total[i] + fruits[i][1];
            step[i + 1] =  fruits[i][0];
            if (fruits[i][0] <= startPos) {
                from = i + 1;
            }
        }
        step[0] = -1;

        for (int i = from + 1; i <= fruits.size(); i++)
        {
            int s = step[i] - startPos;
            if (s > k) {
                break;
            }
            int fruitsForward = total[i] - total[from];
            int fruitsBackward = 0;
            int r = k - s * 2;
            if (r > 0) {
                int j = searchL(step, startPos - r);
                fruitsBackward = total[from] - total[j];
            }
            
            ans = max(ans, fruitsForward + fruitsBackward);
        }

        for (int i = from; i > 0; i--)
        {
            int s = startPos - step[i];
            if (s > k) {
                break;
            }
            int fruitsForward = total[from] - total[i - 1];
            int fruitsBackward = 0;
            int r = k - s * 2;
            if (r > 0) {
                int j = searchR(step, startPos + r);
                fruitsBackward = total[j] - total[from];
            }
            
            ans = max(ans, fruitsForward + fruitsBackward);
        }
            
        
        return ans;        
    }
};

int main()
{
    Solution s;
    vector<vector<int>> fruits = {{2, 8}, {6, 3}, {8, 6}};
    cout << s.maxTotalFruits(fruits, 5, 200) << endl;

    fruits = {{0, 3}, {6, 4}, {8, 5}};
    cout << s.maxTotalFruits(fruits, 3, 200) << endl;

    fruits = {{0, 9}, {4, 1}, {5, 7}, {6, 2}, {7, 4}, {10, 9}};
    cout << s.maxTotalFruits(fruits, 5, 4) << endl;
}
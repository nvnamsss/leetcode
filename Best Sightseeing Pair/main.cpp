/*
You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.

The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.

Return the maximum score of a pair of sightseeing spots.

 

Example 1:

Input: values = [8,1,5,2,6]
Output: 11
Explanation: i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
Example 2:

Input: values = [1,2]
Output: 2
 

Constraints:

2 <= values.length <= 5 * 104
1 <= values[i] <= 1000
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int ans = 0;
        int m = values[0];

        for (int i = 1; i < values.size(); i++)
        {
            ans = max(ans, m + values[i] - i);
            m = max(m, values[i] + i);
        }

        return ans;        
        // while (i + 1 < values.size()) {
        //     int j = i + 1;
        //     while (j < values.size()) {
        //         ans = max(ans, values[i] + values[j] + i - j);
        //         if (values[i] - (j - i) < values[j]) {
        //             cout << "i: " << i << " j: " << j << endl;
        //             break;
        //         }
        //         j++;
        //     }
            
        //     i = j;
        // }
        // return ans;
    }
};

int main() {
    vector<int> values = vector<int>{1,2};
    Solution s;
    int rs = s.maxScoreSightseeingPair(values);
    cout << "rs: " << rs << endl;

    values = vector<int>{8,1,5,2,6};
    rs = s.maxScoreSightseeingPair(values);
    cout << "rs: " << rs << endl;

    values = vector<int>{1,3,5};
    rs = s.maxScoreSightseeingPair(values);
    cout << "rs: " << rs << endl;

    values = vector<int>{4,7,5,8};
    rs = s.maxScoreSightseeingPair(values);
    cout << "rs: " << rs << endl;
}
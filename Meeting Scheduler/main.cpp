/*
Given the availability time slots arrays slots1 and slots2 of two people and a meeting duration duration, return the earliest time slot that works for both of them and is of duration duration.

If there is no common time slot that satisfies the requirements, return an empty array.

The format of a time slot is an array of two elements [start, end] representing an inclusive time range from start to end.

It is guaranteed that no two availability slots of the same person intersect with each other. That is, for any two time slots [start1, end1] and [start2, end2] of the same person, either start1 > end2 or start2 > end1.

 

Example 1:

Input: slots1 = [[10,50],[60,120],[140,210]], slots2 = [[0,15],[60,70]], duration = 8
Output: [60,68]
Example 2:

Input: slots1 = [[10,50],[60,120],[140,210]], slots2 = [[0,15],[60,70]], duration = 12
Output: []
 

Constraints:

1 <= slots1.length, slots2.length <= 104
slots1[i].length, slots2[i].length == 2
slots1[i][0] < slots1[i][1]
slots2[i][0] < slots2[i][1]
0 <= slots1[i][j], slots2[i][j] <= 109
1 <= duration <= 106
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        int i1 = 0;
        int i2 = 0;
        while (i1 < slots1.size() && i2 < slots2.size()) {
            int f1 = slots1[i1][0];
            int t1 = slots1[i1][1];
            int f2 = slots2[i2][0];
            int t2 = slots2[i2][1];

            int f = max(f1,f2);
            int t = min(t1,t2);
            if (f + duration <= t ) {
                return {f, f + duration};
            }

            if (t1 > t2) {
                i2++;
            } else {
                i1++;
            }
        }

        return {};        
    }
};

int main() {
    Solution s;
    vector<vector<int>> slots1 = {{10,50},{60,120},{140,210}};
    vector<vector<int>> slots2 = {{0,15},{60,70}};

    vector<int> ans = s.minAvailableDuration(slots1, slots2, 8);
    cout << ans[0] << "," << ans[1] << endl;
}
/*
You are given a 0-indexed 2D integer array flowers, where flowers[i] = [starti, endi] means the ith flower will be in full bloom from starti to endi (inclusive). You are also given a 0-indexed integer array people of size n, where people[i] is the time that the ith person will arrive to see the flowers.

Return an integer array answer of size n, where answer[i] is the number of flowers that are in full bloom when the ith person arrives.



Example 1:


Input: flowers = [[1,6],[3,7],[9,12],[4,13]], poeple = [2,3,7,11]
Output: [1,2,2,2]
Explanation: The figure above shows the times when the flowers are in full bloom and when the people arrive.
For each person, we return the number of flowers in full bloom during their arrival.
Example 2:


Input: flowers = [[1,10],[3,3]], poeple = [3,3,2]
Output: [2,2,1]
Explanation: The figure above shows the times when the flowers are in full bloom and when the people arrive.
For each person, we return the number of flowers in full bloom during their arrival.


Constraints:

1 <= flowers.length <= 5 * 104
flowers[i].length == 2
1 <= starti <= endi <= 109
1 <= people.length <= 5 * 104
1 <= people[i] <= 109
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int search(vector<int>& arr, int target) {
        int l = 0;
        int r = arr.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (arr[m] > target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return l;
    }
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people)
    {
        int n = flowers.size();
        vector<int> starts = vector<int>(n);
        vector<int> ends = vector<int>(n);
        for (int i = 0; i < flowers.size(); i++)
        {
            starts[i] = flowers[i][0];
            ends[i] = flowers[i][1];
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        vector<int> ans = vector<int>(people.size());
        for (int i = 0; i < people.size(); i++)
        {
            int t = people[i];
            int start = search(starts, t);
            int end = search(ends, t - 1);
            ans[i] = start - end;
        }
        
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> flowers = {{1,6},{3,7},{9,12},{4,13}};
    vector<int> people = {2,3,7,11};
    s.fullBloomFlowers(flowers, people);
}
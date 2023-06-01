#include <bits/stdc++.h>
using namespace std;

class Compare {
    public:
    bool operator() (int a, int b) {
        return a > b;
    }
};
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, Compare> pq;
        int i = 0;
        int sum = 0;
        for (; i < heights.size() - 1; i++)
        {
            if (heights[i] >= heights[i+1]) {
                continue;
            }

            pq.push(heights[i + 1] - heights[i]);
            while (pq.size() > ladders) {
                int m = pq.top();
                pq.pop();
                sum += m;
            }

            if (sum > bricks) {
                break;
            }
        }
        return i;
    }
};

int main() {
    Solution s;
    vector<int> heights = {4,12,2,7,3,18,20,3,19};
    cout << s.furthestBuilding(heights, 10, 2) << endl;

    heights = {14,3,19,3};
    cout << s.furthestBuilding(heights, 17, 0) << endl;

    heights = {1};
    cout << s.furthestBuilding(heights, 17, 0) << endl;
}
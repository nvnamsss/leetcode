#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans = 0;
        int last = -1;
        int n = seats.size();
        for (int i = 0; i < n; i++)
        {
            if (seats[i] == 1) {
                if (last == -1) {
                    ans = i;
                } else {
                    int mid = (i + last + 1) / 2;
                    ans = max(ans, i - mid);
                }
                last = i;
            }
        }
        
        ans = max(ans, n - 1 - last);

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> seats = {1,0,0,1};
    s.maxDistToClosest(seats);
}
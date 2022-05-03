#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solution(vector<int>& arr, int n) {
        unordered_map<int, int> m;
        for (int i = 0; i < arr.size(); i++)
        {
            m[arr[i]]++;
        }

        if (n%2 == 0 && m[n/2] > 1) return true;

        for (int i = 0; i < arr.size(); i++)
        {
            int rest = n - arr[i];
            if (m[rest] > 0) return true;
        }
        
        return false;
    }
};

int main() {
    Solution s;
    vector<int> arr = {5,3,9,13};
    cout << s.solution(arr, 8) << endl;
    arr = {5,3,9,13};
    cout << s.solution(arr, 7) << endl;

}
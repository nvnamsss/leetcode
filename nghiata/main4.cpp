#include <bits/stdc++.h>
using namespace std;

class Solution {
    int calculate(string s) {
        int n = s.size(); 

        int ans = 0;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[i] == s[j]) {
                j++;
            }

            ans += floor((j - i) / 2);
            i = j;
        }

        return ans;
    }
public:
    vector<int> solution(vector<string>& arr) {
        vector<int> res = vector<int>(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            string s = arr[i];
            res[i] = calculate(s);
        }

        return res;
    }
};

int main() {
    Solution sol;
    
    vector<string> testCases = {
        "aaaaaaa",
        "AABAAB",
        "ABAB",
        "AAAA",
        "BBAABB"
    };
    
    vector<int> results = sol.solution(testCases);
    
    cout << "Results for each test case:" << endl;
    for (int i = 0; i < results.size(); i++) {
        cout << "Test case \"" << testCases[i] << "\": " << results[i] << endl;
    }
    
    return 0;
}


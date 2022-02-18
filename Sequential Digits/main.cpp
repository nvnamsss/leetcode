#include <bits/stdc++.h>
using namespace std;

class Solution {
    int allone(int digits) {
        int rs = 0;
        for (int i = 0; i < digits; i++)
        {
            rs = rs * 10 + 1;
        }
        return rs;
    }

    int first(int digits) {
        int rs = 0;
        for (int i = 1; i <= digits; i++)
        {
            rs = rs * 10 + i;
        }
        return rs;
    }

    vector<int> gen(int firstDigit, int lastDigit) {
        vector<int> rs = {};
        for (int i = firstDigit; i <= lastDigit; i++)
        {
            int all1 = allone(i);
            int g = first(i);
            rs.push_back(g);
            for (int j = i; j < 9; j++)
            {
                g += all1;
                rs.push_back(g);
            }
            
        }
        return rs;
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans = {};
        int firstDigit = floor(log10(low) + 1);
        int lastDigit = floor(log10(high) + 1);
        vector<int> generated = gen(firstDigit, lastDigit);
        for (int i = 0; i < generated.size(); i++)
        {
            if (low <= generated[i] && generated[i] <= high) {
                ans.push_back(generated[i]);
            }
        }
        
        return ans;
    }
};

void print(vector<int>& vs) {
    for (int i = 0; i < vs.size(); i++)
    {
        cout << vs[i] << " ";
    }
    cout << endl;
}

int main() {
    Solution s;
    vector<int> rs = s.sequentialDigits(100, 300);
    print(rs);

    rs = s.sequentialDigits(1000, 13000);
    print(rs);
}
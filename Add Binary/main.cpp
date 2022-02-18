#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int m = a.size() - 1;
        int n = b.size() - 1;
        int r = 0;
        while (m >= 0 && n >= 0) {
            int v = a[m] - '0' + b[n] - '0' + r;
            char c = (v)%2 + '0';
            r = v / 2;
            ans = c + ans;
            m--;
            n--;
        }

        while (m >= 0) {
            int v = a[m] - '0' + r;
            char c = (v)%2 + '0';
            r = v / 2;
            ans = c + ans;
            m--;
        }

        while (n >= 0) {
            int v = b[n] - '0' + r;
            char c = (v)%2 + '0';
            r = v / 2;
            ans = c + ans;
            n--;
        }

        if (r) {
            ans = '1' + ans;
        }

        return ans;
    }
};

int main() {
    Solution s;
    cout << s.addBinary("11", "1") << endl; 
}
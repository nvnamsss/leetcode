#include <bits/stdc++.h>
using namespace std;

int maxDistance(string s) {
    int last = -1;
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1') {
            if (last != -1) {
                ans = max(ans, i - last);
            }
            last = i;
        }
    }
    return ans;
}

int main() {
    cout << maxDistance("1000000100101101000000000000") << endl;
}


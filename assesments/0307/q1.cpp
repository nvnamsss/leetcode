/*
Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.

You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.

 

Example 1:

Input: time = "19:34"
Output: "19:39"
Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.
It is not 19:33, because this occurs 23 hours and 59 minutes later.
Example 2:

Input: time = "23:59"
Output: "22:22"
Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22.
It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.
 

Constraints:

time.length == 5
time is a valid time in the form "HH:MM".
0 <= HH < 24
0 <= MM < 60
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> digitsOfTime(string time) {
        return {time[0] - '0', time[1] - '0', time[3] - '0', time[4] - '0'};
    }

    int string2time(string time) {
        int v  = time[0] - '0';
        v = v * 10 + (time[1] - '0');
        v = v * 10 + (time[3] - '0');
        v = v * 10 + (time[4] - '0');
        return v;
    }

    string time2string(int t) {
        string s = "00:00";
        s[4] = (t % 10 + '0');
        t = t / 10;
        s[3] = (t % 10 + '0');
        t = t / 10;
        s[1] = (t % 10 + '0');
        t = t / 10;
        s[0] = (t % 10 + '0');
        t = t / 10;
        return s;
    }
    int dif(int t1, int t2) {
        if (t2 < t1) {
            t2 += 2400;
        }

        return t2 - t1;
    }

    void permutate(vector<int>& digits, vector<int>& p, int pos, int v) {
        if (pos == 4) {
            p.push_back(v);
            return;
        }

        for (int i = 0; i < digits.size(); i++)
        {
            permutate(digits, p, pos + 1, v * 10 + digits[i]);
        }
    }

public:
    string nextClosestTime(string time) {
        vector<int> digits = digitsOfTime(time);
        vector<int> p;
        int t1 = string2time(time);
        int ans = 2400;
        int md = 2400;
        permutate(digits, p, 0, 0);
        for (int i = 0; i < p.size(); i++)
        {
            int d = dif(t1, p[i]);
            if (d > 0 && d < md) {
                md = min(ans, d);
                ans = p[i];
            }
        }
        
        return time2string(ans);
    }
};

int main() {
    Solution s;
    cout << s.nextClosestTime("19:34") << endl;
}
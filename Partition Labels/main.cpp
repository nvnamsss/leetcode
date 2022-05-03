/*
You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

Return a list of integers representing the size of these parts.

 

Example 1:

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
Example 2:

Input: s = "eccbbbbdec"
Output: [10]
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last = vector<int>(26);
        vector<int> rs;
        int begin = -1;
        int j = 0;
        for (int i = 0; i < s.size(); i++)
        {
            last[s[i] - 'a'] = i;
        }

        for (int i = 0; i < s.size(); i++)
        {
            j = max(j, last[s[i] - 'a']);
            if (i == j) {
                rs.push_back(i - begin);
                begin = i;
            }
        }
                
        return rs;
    }
};

void log(vector<int> v) {
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " "; 
    }
    cout << endl;
}

int main() {
    Solution s;
    vector<int> rs = s.partitionLabels("ababcbacadefegdehijhklij");
    log(rs);
    rs = s.partitionLabels("eccbbbbdec");
    log(rs);
    rs = s.partitionLabels("a");
    log(rs);
    rs = s.partitionLabels("jybmxfgseq");
    log(rs);
}
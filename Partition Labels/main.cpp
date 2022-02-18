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
        vector<int> partitions = vector<int>(s.size() + 1, s.size());
        unordered_map<char, int> last;
        int slow = 0;
        int fast = 1;
        int count = 0;
        partitions[0] = 0;
        for (int i = 0; i < 26; i++)
        {
            last['a' + i] = -1;
        }
        
        for (int i = 0; i < s.size(); i++)
        {
            int l = last[s[i]];
            if (l == -1) {
                partitions[count] = i;
                count++;
            } else {
                int j = count - 1;
                while (l < partitions[j]) {
                    j--;
                }
                count = j + 1;
            } 

            last[s[i]] = i;
        }
        partitions[count] = s.size();
        vector<int> rs;
        for (int i = 0; i < count; i++)
        {
            rs.push_back(partitions[i + 1] - partitions[i]);
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
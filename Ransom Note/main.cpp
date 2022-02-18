#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;
        for (int i = 0; i < magazine.size(); i++)
        {
            if (map.find(magazine[i]) == map.end()) {
                map.insert({magazine[i], 0});
            }
            map[magazine[i]]++;
        }
        
        for (int i = 0; i < ransomNote.size(); i++)
        {
            if (map.find(ransomNote[i]) == map.end()) return false;
            if (map[ransomNote[i]]-- < 0) return false;
        }
        
        return true;
    }
};
int main() {
    Solution s;
    string rn = "aa";
    string magazine = "aab";

    s.canConstruct(rn, magazine);
}
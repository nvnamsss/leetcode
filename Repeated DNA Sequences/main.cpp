#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> map;
        vector<string> rs;
        if (s.size() < 10) {
            return rs;
        }

        string dna = "";
        for (int i = 0; i < 10; i++)
        {
            dna += s[i];
        }
        
        map.insert({dna, 1});

        for (int i = 10; i < s.size(); i++)
        {
            dna = dna.substr(1, 9) + s[i];
            if (map.find(dna) == map.end()) {
                map.insert({dna, 1});
            }
            map[dna]++;
        }
        
        for (auto &&v: map) {
            if (v.second > 1) {
                rs.push_back(v.first);
            }
        }

        return rs;
    }
};
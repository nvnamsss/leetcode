/*
You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.

Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.

 

Example 1:

Input: equations = ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
There is no way to assign the variables to satisfy both equations.
Example 2:

Input: equations = ["b==a","a==b"]
Output: true
Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
 

Constraints:

1 <= equations.length <= 500
equations[i].length == 4
equations[i][0] is a lowercase letter.
equations[i][1] is either '=' or '!'.
equations[i][2] is '='.
equations[i][3] is a lowercase letter.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        unordered_map<char, unordered_map<char, bool>> m;
        for (int i = 0; i < equations.size(); i++)
        {
            char v1 = equations[i][0];
            bool op = equations[i][1] == '=';
            char v2 = equations[i][3];

            if (m.find(v1) != m.end() && m[v1].find(v2) != m[v1].end() && m[v1][v2] != op) {
                return false;              
            }

            if (op) {
                for (auto &&it : m[v1]) {
                    m[v2][it.first] = op;
                    m[it.first][v2] = op;
                }                
            }

            m[v1][v2] = op;
            m[v2][v1] = op;
        }
        return true;
    }
};

int main() {
    vector<string> eqs = {"a==b","b==a"};
    Solution s;
    s.equationsPossible(eqs);

    eqs = {"a==b","b==c","c!=a"};
    cout << s.equationsPossible(eqs) << endl;
    eqs = {"a==b","b!=c","c==a", "d==b", "a!=d"};
    cout << s.equationsPossible(eqs) << endl;

}
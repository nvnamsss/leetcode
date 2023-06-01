/*
You are given an array of strings ideas that represents a list of names to be used in the process of naming a company. The process of naming a company is as follows:

Choose 2 distinct names from ideas, call them ideaA and ideaB.
Swap the first letters of ideaA and ideaB with each other.
If both of the new names are not found in the original ideas, then the name ideaA ideaB (the concatenation of ideaA and ideaB, separated by a space) is a valid company name.
Otherwise, it is not a valid name.
Return the number of distinct valid names for the company.



Example 1:

Input: ideas = ["coffee","donuts","time","toffee"]
Output: 6
Explanation: The following selections are valid:
- ("coffee", "donuts"): The company name created is "doffee conuts".
- ("donuts", "coffee"): The company name created is "conuts doffee".
- ("donuts", "time"): The company name created is "tonuts dime".
- ("donuts", "toffee"): The company name created is "tonuts doffee".
- ("time", "donuts"): The company name created is "dime tonuts".
- ("toffee", "donuts"): The company name created is "doffee tonuts".
Therefore, there are a total of 6 distinct company names.

The following are some examples of invalid selections:
- ("coffee", "time"): The name "toffee" formed after swapping already exists in the original array.
- ("time", "toffee"): Both names are still the same after swapping and exist in the original array.
- ("coffee", "toffee"): Both names formed after swapping already exist in the original array.
Example 2:

Input: ideas = ["lack","back"]
Output: 0
Explanation: There are no valid selections. Therefore, 0 is returned.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    long long factorial(int n)
    {
        int v = 1;
        for (int i = 1; i <= n; i++)
        {
            v *= i;
        }
        return v;
    }

    long long nPr(int n, int r)
    {
        return factorial(n) / factorial(n - r);
    }

    long long counting(vector<string>& ideas) {
long long ans = nPr(ideas.size(), 2);
        unordered_map<string, vector<int>> suffixes;
        unordered_map<char, int> prefixes;
        unordered_map<char, vector<string>> p2s;

        for (int i = 0; i < ideas.size(); i++)
        {
            char p = ideas[i][0];
            string s = ideas[i].substr(1, ideas[i].size() - 1);

            suffixes[s].push_back(i);
            prefixes[p]++;
            p2s[p].push_back(s);
        }
        long long invalid = 0;

        // for (auto&& it: suffixes) {
        //     if (it.second.size() == 1) {
        //         continue;
        //     }

        //     for (int i = 0; i < it.second.size(); i++)
        //     {
        //         char p = ideas[it.second[i]][0];
        //         if (prefixes[p] > 1) {
        //             int reduce = (prefixes[p] - 1) * it.second.size();
        //             invalid += (prefixes[p] - 1) * it.second.size();

        //         }
        //     }

        // }

        for (int i = 0; i < ideas.size(); i++)
        {
            char p = ideas[i][0];
            string s = ideas[i].substr(1, ideas[i].size() - 1);

            invalid += suffixes[s].size() - 1;
            invalid += prefixes[p] - 1;

            vector<string> ss = p2s[p];
            for (int j = 0; j < ss.size(); j++)
            {
                if (s == ss[j]) {
                    continue;
                }
                invalid += suffixes[ss[j]].size();
                /* code */
            }
        }

        // for (auto &&it: suffixes) {
        //     string s = 'a' + it.first;
        //     for (int i = 0; i < 26; i++)
        //     {
        //         char c = 'a' + i;
        //         s[0] = c;
        //         if (mideas.find(s) != mideas.end()) {
        //             invalid += it.second - 1;
        //         }
        //     }
        // }
        return ans - invalid;
    }

    long long group(vector<string>& ideas) {
        vector<unordered_set<string>> groups = vector<unordered_set<string>>(26);
        long long ans = 0;
        for (int i = 0; i < ideas.size(); i++)
        {
            int p = ideas[i][0] - 'a';
            string s = ideas[i].substr(1);
            groups[p].insert(s);
        }
        
        for (int i = 0; i < 25; i++)
        {
            for (int j = i + 1; j < 26; j++)
            {
                int mutual = 0;
                for (auto& it: groups[i]) {
                    if (groups[j].find(it) != groups[j].end()) {
                        mutual++;
                    }
                }

                ans += 2 * (groups[i].size() - mutual) * (groups[j].size() - mutual);
            }
        }
        
        return ans;
    }
public:
    long long distinctNames(vector<string> &ideas)
    {
        return group(ideas);
    }
};

int main()
{
    Solution s;
    vector<string> ideas = {"coffee", "donuts", "time", "toffee"};
    cout << s.distinctNames(ideas) << endl;

    ideas = {"lsab", "b"};
    cout << s.distinctNames(ideas) << endl;
}
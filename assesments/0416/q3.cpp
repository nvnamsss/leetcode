#include <bits/stdc++.h>
using namespace std;

class Solution{
    bool compare(vector<string>& company_names, vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            if (a[1] == b[1]) {
                return company_names[a[2]].compare(company_names[b[2]]) < 0;
            }
            return a[1] > b[1];
        }
        return a[0] > b[0];
    }
public:
    vector<string> solution(vector<string>& company_names, vector<vector<int>>& scores) {
        vector<string> ans;
        vector<vector<int>> m = vector<vector<int>>(company_names.size(), vector<int>(3, 0));
        for (int i = 0; i < company_names.size(); i++)
        {
            int total = 0;
            int count80 = 0;
            for (int j = 0; j < scores[i].size(); j++)
            {
                total += scores[i][j];
                if (scores[i][j] >= 80) count80++;
            }
            
            m[i][0] = count80;
            m[i][1] = total;
            m[i][2] = i;
        }
        
        for (int i = 0; i < m.size(); i++)
        {
            int sIndex = i;
            for (int j = i + 1; j < m.size(); j++)
            {
                if (compare(company_names, m[sIndex], m[j])) {
                    sIndex = j;
                }
            }
            swap(m[i], m[sIndex]);
        }
        
        for (int i = 0; i < m.size(); i++)
        {
            ans.push_back(company_names[m[i][2]]);
        }
        
        return ans;
    }
};

void print(vector<string>& s) {
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;
} 
int main() {
    Solution s;
    vector<string> companies = {"warehouse", "parkworld", "eggandbacon", "xyz", "hellomark", "olive"};
    vector<vector<int>> scores = {
        {74,76,65,90,75},
        {95,70,85,60,65},
        {75,75,75,75,80},
        {90,100,85,75,70},
        {100,79,100,70,79},
        {70,71,100,80,39}
    };
    s.solution(companies, scores);
    // vector<string> ans = s.solution(companies, scores);
    // print(ans);
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> covidspan(vector<int>& cases) {
        vector<int> ans = vector<int>(cases.size(), -1); // init an array with cases.size() elements with value equal to -1
        stack<int> s;
        for (int i = 0; i < cases.size(); i++)
        {
            while (!s.empty() && cases[s.top()] > cases[i]) {
                ans[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};

void print(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++)
    {
        cout << arr[i] << ",";
    }
    cout << arr[arr.size() - 1];
    cout << endl;
}

vector<int> parseInput(string s) {
    s += ",";
    string value = "";
    vector<int> input;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ',') {
            input.push_back(stoi(value));
            value = "";
        } else {
            value += s[i];
        }
    }

    return input;
}

int main() {
    Solution s;
    string input;
    cin >> input;
    
    vector<int> cases = parseInput(input);
    print(cases);
    // vector<int> cases = {104,99,76,94,78,77,75};
    vector<int> ans = s.covidspan(cases);
    print(ans);
}
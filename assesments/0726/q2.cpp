#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool simulate(vector<vector<int>> &families, int queue)
    {
        int lastTime = 0;
        vector<int> queues = vector<int>(queue);
        for (int i = 0; i < families.size(); i++)
        {
            int peoples = families[i][1];
            int currentTime = families[i][0];
            for (int j = 0; j < queue; j++)
            {
                int timePassed = currentTime - lastTime;
                queues[j] = max(0, queues[j] - timePassed);
            }
            int q = 0;
            while (q < queue && peoples > 0) {
                int rest = max(9 - queues[q], 0);
                int pplToQueue = min(rest, peoples);
                queues[q] += pplToQueue;
                peoples -= pplToQueue;
                q++;
            }

            if (q == queue && peoples > 0) {
                return false;
            }
            lastTime = currentTime;
        }
        return true;
    }

public:
    int covidVaccination(vector<vector<int>> &families)
    {
        if (families.size() == 0) {
            return 0;
        }
        sort(families.begin(), families.end());
        int l = 1;
        int totalPeoples = 0;
        for (int i = 0; i < families.size(); i++)
        {
            totalPeoples += families[i][1];
        }
        int r = ceil(totalPeoples / 9.0);
        
        while (l <= r) {
            int m = (l + r) / 2;
            bool acceptable = simulate(families, m);
            if (acceptable) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return l;
    }
};

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
    int lines = 0;
    cin >> lines;
    vector<vector<int>> families;
    for (int i = 0; i < lines; i++)
    {
        string input;
        cin >> input;
        families.push_back(parseInput(input));
    }
    

    cout << s.covidVaccination(families) << endl;
}
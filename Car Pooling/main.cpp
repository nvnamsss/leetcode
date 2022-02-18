#include <bits/stdc++.h>
using namespace std;

class Solution
{
    struct Milestone
    {
        int at;
        int amount;
        Milestone(int at, int amount)
        {
            this->at = at;
            this->amount = amount;
        }
    };

public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        int c = 0;
        vector<Milestone> milestones;
        for (int i = 0; i < trips.size(); i++)
        {
            milestones.push_back(Milestone(trips[i][1], trips[i][0]));
            milestones.push_back(Milestone(trips[i][2], -trips[i][0]));
        }
        sort(milestones.begin(), milestones.end(), [](const Milestone& m1, const Milestone& m2) {
            if (m1.at == m2.at) return m1.amount < m2.amount;
            return m1.at < m2.at;
        });

        for (int i = 0; i < milestones.size(); i++)
        {
            c += milestones[i].amount;
            if (c > capacity) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution s;
    vector<vector<int>> trips = {{2,1,5},{3,3,7}};
    bool rs = s.carPooling(trips, 4);
    cout << rs << endl;

    rs = s.carPooling(trips, 5);
    cout << rs << endl;

}
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void print(vector<int> set)
    {
        cout << "List: ";
        for (int loop = 0; loop < set.size(); loop++)
        {
            cout << set[loop];
        }
        cout << endl;
    }
    int lessPosition(vector<int> &candidates, int target)
    {
        int index = candidates.size() - 1;
        for (int loop = 0; loop < candidates.size(); loop++)
        {
            if (candidates[loop] > target)
            {
                index = loop;
                break;
            }
        }

        return index;
    }

    void solve(vector<vector<int> > &result, vector<int> &subset, vector<int> &candidates, int start, int target)
    {
        if (start > candidates.size() - 1)
        {
            return;
        }

        if (target < 0) return;

        if (target == 0)
        {
            result.push_back(subset);
            return;
        }

        if (target - candidates[start] <= target)
        {
            subset.push_back(candidates[start]);
            solve(result, subset, candidates, start, target - candidates[start]);
            subset.pop_back();
        }

        solve(result, subset, candidates, start + 1, target);
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target)
    {
        //divided by

        //divide target by an element, we got remainder, keep divide remainder until we got zero remainder
        /*
            So we move from number that less than target to lower
            2 3 5 -> 8
            8 / 5 -> r = 3
            keep finding like that until we got r = 0
            a kind of recursive?

        */
        vector<vector<int> > result = vector<vector<int> >();
        vector<int> subset = vector<int>();
        solve(result, subset, candidates, 0, target);
        
        for (int loop = 0; loop < result.size(); loop++)
        {
            print(result[loop]);
        }
        return result;
    }
};

int main()
{
    Solution s = Solution();
    vector<int> t1 = vector<int>();
    t1.push_back(2);
    t1.push_back(3);
    t1.push_back(6);
    t1.push_back(7);
    s.combinationSum(t1, 7);
    cout << "done";
    cin.get();
}
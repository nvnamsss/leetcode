#include <bits/stdc++.h>
using namespace std;

class RandomizedSet
{
    set<int> s;
    vector<int> v;

public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (s.find(val) == s.end())
        {
            s.insert(val);
            v.push_back(val);
            return true;
        }

        return false;
    }

    bool remove(int val)
    {
        if (s.find(val) == s.end())
        {
            return false;
        }

        s.erase(val);
        auto it = find(v.begin(), v.end(), val);
        int index = it - v.begin();
        v[index] = v[v.size() - 1];
        v.pop_back();
        return true;
    }

    int getRandom()
    {
        int r = rand() % v.size();
        return v[r];
    }
};
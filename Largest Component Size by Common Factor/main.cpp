/*
You are given an integer array of unique positive integers nums. Consider the following graph:

There are nums.length nodes, labeled nums[0] to nums[nums.length - 1],
There is an undirected edge between nums[i] and nums[j] if nums[i] and nums[j] share a common factor greater than 1.
Return the size of the largest connected component in the graph.

 

Example 1:


Input: nums = [4,6,15,35]
Output: 4
Example 2:


Input: nums = [20,50,9,63]
Output: 2
Example 3:


Input: nums = [2,3,6,7,4,12,21,39]
Output: 8
 

Constraints:

1 <= nums.length <= 2 * 104
1 <= nums[i] <= 105
All the values of nums are unique.
*/

#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
    vector<int> idx;

public:
    vector<int> size;
    UnionFind(int n)
    {
        idx = vector<int>(n);
        size = vector<int>(n, 1);
        for (int i = 0; i < n; i++)
        {
            idx[i] = i;
        }
    }

    int find(int x)
    {
        while (idx[x] != x)
        {

            idx[x] = idx[idx[x]];
            x = idx[x];
        }
        return x;
        // if (idx[x] == x) return x;
        // return idx[x] = find(idx[x]);
    }

    void merge(int x, int y)
    {
        int a = find(x);
        int b = find(y);
        if (a == b)
            return;
        if (size[a] < size[b])
        {
            int t = a;
            a = b;
            b = t;
        }

        size[a] += size[b];
        idx[b] = idx[a];
    }

    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }
};

class Solution
{
    vector<int> sieve(int n)
    {
        vector<int> spf = vector<int>(n + 1);
        for (int i = 0; i <= n; i++)
        {
            spf[i] = i;
        }

        for (int i = 2; i * i <= n; i++)
        {
            if (spf[i] == i)
            {
                for (int j = i * i; j <= n; j = j + i)
                {
                    if (spf[j] == j)
                    {
                        spf[j] = i;
                    }
                }
            }
        }

        return spf;
    }

    vector<int> getPrimes(int x, vector<int> &spf)
    {
        vector<int> primes;

        while (x != 1)
        {
            int p = spf[x];
            primes.push_back(p);
            while (x % p == 0)
                x = x / p;
        }

        return primes;
    }

public:
    int largestComponentSize(vector<int> &nums)
    {
        unordered_map<int, vector<int>> m;
        UnionFind uf = UnionFind(nums.size() + 1);
        int M = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            M = max(M, nums[i]);
        }

        vector<int> spf = sieve(M);

        for (int i = 0; i < nums.size(); i++)
        {
            int cur = nums[i];
            vector<int> primes = getPrimes(cur, spf);
            for (int j = 0; j < primes.size(); j++)
            {
                m[primes[j]].push_back(i);
            }

            // if (cur % 2 == 0)
            // {
            //     m[2].push_back(i);
            //     while (cur % 2 == 0)
            //         cur = cur / 2;
            // }

            // for (int p = 3; p <= sqrt(cur); p++)
            // {
            //     if (cur % p == 0)
            //     {
            //         m[p].push_back(i);
            //         while (cur % p == 0)
            //             cur = cur / p;
            //     }
            // }
            // if (cur > 1)
            // {
            //     m[cur].push_back(i);
            // }
        }

        for (auto kv : m)
        {
            for (int i = 0; i < kv.second.size() - 1; i++)
            {
                uf.merge(kv.second[i], kv.second[i + 1]);
            }
        }

        int ans = 0;
        for (int i = 0; i < uf.size.size(); i++)
        {
            ans = max(ans, uf.size[i]);
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {4, 6, 15, 35};

    int rs = s.largestComponentSize(nums);
    cout << rs << endl;

    nums = {20, 50, 9, 63};
    rs = s.largestComponentSize(nums);
    cout << rs << endl;

    nums = {2, 3, 6, 7, 4, 12, 21, 39};
    rs = s.largestComponentSize(nums);
    cout << rs << endl;

    nums = {1,2,3,4,5,6,7,8,9};
    rs = s.largestComponentSize(nums);
    cout << rs << endl;
}
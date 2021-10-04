#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int sign(int a)
    {
        if (a > 0)
            return 1;
        if (a == 0)
            return 0;
        return -1;
    }
    bool inBetween(vector<int> p, vector<int> i, vector<int> q)
    {
        bool a = i[0] >= p[0] && i[0] <= q[0] || i[0] <= p[0] && i[0] >= q[0];
        bool b = i[1] >= p[1] && i[1] <= q[1] || i[1] <= p[1] && i[1] >= q[1];
        return a && b;
    }

    vector<int> Hull(vector<int> &last, vector<vector<int>> &points)
    {
        vector<int> endpoint = points[0];
        for (int loop = 0; loop < points.size(); loop++)
        {
            int i = sign((endpoint[0] - last[0]) * (points[loop][1] - last[1]) - (endpoint[1] - last[1]) * (points[loop][0] - last[0]));

            if ((endpoint[0] == last[0] && endpoint[1] == last[1]) || i > 0)
            {
                endpoint = points[loop];
            }
        }

        return endpoint;
    }
    static int orientation(vector<int> p, vector<int> q, vector<int> r)
    {
        return (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1]);
    }
    static int distance(vector<int> p, vector<int> q)
    {
        return (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
    }
    vector<int> bottomLeft(vector<vector<int>> &points)
    {
        vector<int> bottomLeft = points[0];
        for (auto &p : points)
            if (p[1] < bottomLeft[1])
                bottomLeft = p;
        return bottomLeft;
    }
    static vector<int> bm;

    static bool comparision(vector<int> a, vector<int> b)
    {
        double diff = orientation(bm, a, b) - orientation(bm, b, a);
        if (diff == 0)
            return distance(bm, a) - distance(bm, b);
        else
            return diff > 0 ? 1 : -1;
    }

public:
    vector<vector<int>> outerTrees(vector<vector<int>> &trees)
    {
        return graham(trees);
    }

    vector<vector<int>> graham(vector<vector<int>> &points)
    {
        if (points.size() <= 1)
            return points;
        bm = bottomLeft(points);
        // bool (func)(vector<int>, vector<int>);
        // func = Solution::comparision;
        sort(points.begin(), points.end(), [](vector<int> a, vector<int> b)
             {
                 double diff = orientation(bm, a, b) - orientation(bm, b, a);
                 if (diff == 0)
                     return distance(bm, a) - distance(bm, b);
                 else
                     return diff > 0 ? 1 : -1;
             });

        int i = points.size() - 1;
        while (i >= 0 && orientation(bm, points[points.size() - 1], points[i]) == 0)
            i--;
        for (int l = i + 1, h = points.size() - 1; l < h; l++, h--)
        {
            vector<int> temp = points[l];
            points[l] = points[h];
            points[h] = temp;
        }

        stack<vector<int>> stack;
        stack.push(points[0]);
        stack.push(points[1]);
        for (int j = 2; j < points.size(); j++)
        {
            vector<int> top = stack.top();
            stack.pop();

            while (orientation(stack.top(), top, points[j]) > 0)
            {
                top = stack.top();
                stack.pop();
            }

            stack.push(top);
            stack.push(points[j]);
        }

        vector<vector<int>> rs;
        while (!stack.empty())
        {
            rs.push_back(stack.top());
            stack.pop();
        }
        return rs;
    }

    vector<vector<int>> jarvis(vector<vector<int>> &trees)
    {
        if (trees.size() < 4)
            return trees;
        vector<vector<int>> hullPoints;
        vector<int> endpoint = trees[0];
        for (int i = 0; i < trees.size(); i++)
        {
            if (trees[i][0] <= endpoint[0])
            {
                if (trees[i][0] == endpoint[0] && trees[i][1] > endpoint[1])
                    continue;
                endpoint = trees[i];
            }
        }

        hullPoints.push_back(endpoint);
        while (true)
        {
            endpoint = Hull(hullPoints[hullPoints.size() - 1], trees);
            if (endpoint[0] == hullPoints[0][0] && endpoint[1] == hullPoints[0][1])
                break;
            hullPoints.push_back(endpoint);
        }

        return hullPoints;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> trees = vector<vector<int>>{
        {1, 1}, {2, 2}, {2, 0}, {2, 4}, {3, 3}, {4, 2}};

    vector<vector<int>> rs = s.outerTrees(trees);
    cout << "Done";
}
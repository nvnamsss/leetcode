#include <bits/stdc++.h>
using namespace std;

// Definition for a QuadTree node.
class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution
{
    Node *recursive(vector<vector<int>> &grid, vector<vector<int>>& dp, vector<vector<int>>& dpZero, int left, int right, int top, int bottom)
    {
        if (grid[bottom][right] && dp[bottom + 1][right + 1] >= (bottom - top + 1)) {
            return new Node(grid[top][left], true);
        }

        if (!grid[bottom][right] && dpZero[bottom + 1][right + 1] >= (bottom - top + 1) ) {
            return new Node(grid[top][left], true);

        }
        if (left == bottom) {
            return new Node(grid[top][bottom], true);
        }

        int middleVertical = (left + right) / 2 + 1;
        int middleHorizontal = (top + bottom) / 2 + 1;
        Node *topleft = recursive(grid, dp, dpZero, left, middleVertical - 1, top, middleHorizontal - 1);
        Node *topright = recursive(grid, dp, dpZero, middleVertical, right, top, middleHorizontal - 1);
        Node *bottomleft = recursive(grid, dp, dpZero, left, middleVertical - 1, middleHorizontal, bottom);
        Node *bottomright = recursive(grid, dp, dpZero, middleVertical, right, middleHorizontal, bottom);

        return new Node(false, false, topleft, topright, bottomleft, bottomright);
    }

public:
    Node *construct(vector<vector<int>> &grid)
    {
        int m = grid.size();
        vector<vector<int>> dp = vector<vector<int>>(m + 1, vector<int>(m + 1));
        vector<vector<int>> dpZero = vector<vector<int>>(m + 1, vector<int>(m + 1));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dp[i + 1][j + 1] = min(dp[i][j], min(dp[i][j + 1], dp[i + 1][j])) + grid[i][j];
                dpZero[i + 1][j + 1] = min(dpZero[i][j], min(dpZero[i + 1][j], dpZero[i][j + 1])) + (1 - grid[i][j]);
                
            }
        }

        return recursive(grid, dp, dpZero, 0, m - 1, 0, m - 1);
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid = {
        {0, 1},
        {1, 0}};

        grid = {{1,1,0,0,0,0,0,0},{1,1,0,0,0,0,0,0},{1,1,0,0,0,0,1,1},{1,1,0,0,0,0,1,1},{0,0,0,0,0,0,1,1},{0,0,0,0,0,0,1,1},{1,1,1,1,1,1,0,0},{1,1,1,1,1,1,0,0}};
    s.construct(grid);
}
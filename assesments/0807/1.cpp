#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    int m, n;
    vector<pair<int, int>> directions = vector<pair<int, int>>{
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}};

public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        bool two = false;
        for (int i = 0; i < bits.size(); i++)
        {
            two = false;
            if (bits[i] == 1)
            {
                two = true;
                i++;
            }
        }

        return !two;
    }

    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL && root2 == NULL)
            return NULL;
        int r1 = root1 != NULL ? root1->val : 0;
        int r2 = root2 != NULL ? root2->val : 0;
        TreeNode *node = new TreeNode(r1 + r2);

        TreeNode *left1 = root1 != NULL ? root1->left : NULL;
        TreeNode *left2 = root2 != NULL ? root2->left : NULL;
        TreeNode *right1 = root1 != NULL ? root1->right : NULL;
        TreeNode *right2 = root2 != NULL ? root2->right : NULL;
        node->left = mergeTrees(left1, left2);
        node->right = mergeTrees(right1, right2);

        return node;
    }

    bool dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, vector<vector<bool>> &memo, int v, int h)
    {
        if (visited[v][h])
        {
            return memo[v][h];
        }
        visited[v][h] = true;
        for (int i = 0; i < 4; i++)
        {
            int x = v + directions[i].first;
            int y = h + directions[i].second;

            if (x < 0 || x >= m || y < 0 || y >= n)
            {
                memo[v][h] = false;
                return false;
            }

            if (grid[x][y] == 0 && !dfs(grid, visited, memo, x, y))
            {
                memo[v][h] = false;
            }

            // return memo[v][h];
        }
        // memo[v][h] = true;
        return memo[v][h];
    }

    int closedIsland(vector<vector<int>> &grid)
    {
        int rs = 0;
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited = vector<vector<bool>>(m, vector<bool>(n, false));
        vector<vector<bool>> memo = vector<vector<bool>>(m, vector<bool>(n, true));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && grid[i][j] == 0)
                {
                    if (dfs(grid, visited, memo, i, j))
                    {
                        cout << "closed at " << i << "-" << j << endl;
                        rs++;
                    }
                }
            }
        }

        return rs;
    }
};

class KthLargest
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;

public:
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;

        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
        }
        while (pq.size() > k)
        {
            pq.pop();
        }
    }

    int add(int val)
    {
        pq.push(val);
        while (pq.size() > k)
        {
            pq.pop();
        }

        int kth = pq.top();
        return kth;
    }
};

int main()
{
    vector<int> nums = vector<int>{4, 5, 8, 2};
    KthLargest k = KthLargest(3, nums);
    int rs = k.add(3);
    rs = k.add(5);
    rs = k.add(10);
    rs = k.add(9);

    rs = k.add(4);

    Solution s;
    vector<vector<int>> grid = vector<vector<int>>{
        {1, 1, 1, 1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 1, 0},
        {1, 0, 1, 0, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 0}};
    // s.closedIsland(grid);

    grid = vector<vector<int>>{
        {0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1},
        {0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0},
        {0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1},
        {1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0},
        {0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1},
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
        {0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1},
        {0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0}
        };

    s.closedIsland(grid);

    grid = vector<vector<int>> {
        {1,1,1,1,1,1,1,0},
        {1,0,0,0,0,1,1,0},
        {1,0,1,0,1,1,1,0},
        {1,0,0,0,0,1,0,1},
        {1,1,1,1,1,1,1,0}
    };
    s.closedIsland(grid);
}
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return NULL;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left != NULL && right != NULL)
            return root;
        if (root->val == p->val || root->val == q->val)
            return root;

        if (left != NULL)
            return left;
        if (right != NULL)
            return right;

        return NULL;
    }

    string multiply(string num1, string num2)
    {
        string rs = "0";
        int length = num1.size();
        for (int i = 0; i < length; i++)
        {
            string a;
            a[0] = num1[i];
            for (int j = i + 1; j < length; j++)
            {
                a = a + '0';
            }
            
            string s = multiply(a, num2);
            
            rs = plus(rs, s);
        }
        return rs;
    }

    string multiply(string num1, char c)
    {
        string rs;
        int size = num1.size();
        int r = 0;
        for (int i = 0; i < size; i++)
        {
            int t = (num1[i] + r - '0') * (c - '0');
            char append = (char)(t % 10 + '0');
            r = t / 10;
            rs = append + rs;
        }

        while (r > 0)
        {
            char append = (char)(r % 10 + '0');
            rs = append + rs;
            r = r / 10;
        }
        return rs;
    }

    string plus(string num1, string num2)
    {
        string rs = "";
        int s1 = num1.size();
        int s2 = num2.size();
        int length = max(s1, s2);
        int r = 0;

        if (s1 < s2)
        {
            for (int i = length - s1; i > 0; i--)
            {
                num1 = '0' + num1;
            }
        }
        else
        {
            for (int i = length - s1; i > 0; i--)
            {
                num2 = '0' + num2;
            }
        }

        for (int i = length - 1; i >= 0; i--)
        {
            int a = num1[i] + num2[i];
            int b = 2 * '0';
            int t = (a - b + r);
            r = t / 10;
            char append = (char)(t % 10 + '0');
            rs = append + rs;
        }

        if (r > 0)
        {
            char append = (char)(r % 10 + '0');
            rs = append + rs;
        }

        return rs;
    }
};

int main()
{
    Solution s;
    string rs = s.multiply("6", "2");
    cout << "result: " << rs << endl;
    rs = s.multiply("123", "456");
    cout << "result: " << rs << endl;
}
/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/

public class TreeNode
{
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null)
    {
        this.val = val;
        this.left = left;
        this.right = right;
    }

    public override string ToString()
    {
        return val.ToString();
    }
}

public class Solution
{
List<IList<int>> rs;
        private void levelOrderBottom(int level, TreeNode node)
        {
            if (rs.Count == level)
            {
                rs.Add(new List<int>());
            }

            rs[level].Add(node.val);

            if (node.left != null) levelOrderBottom(level + 1, node.left);
            if (node.right != null) levelOrderBottom(level + 1, node.right);

        }

        public IList<IList<int>> LevelOrderBottom(TreeNode root)
        {
            rs = new List<IList<int>>();
            if (root == null) return rs;

            levelOrderBottom(0, root);
            rs.Reverse();
            
            return rs;
        }
}
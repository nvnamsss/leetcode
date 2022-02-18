/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
        private int depth(TreeNode root, int d)
        {
            int dl = d;
            int dr = d;
            if (root.left != null) dl = depth(root.left, dl + 1);
            if (root.right != null) dr = depth(root.right, dr + 1);

            return Math.Max(dl, dr);
        }

        public int MaxDepth(TreeNode root)
        {
            if (root == null) return 0;
            int d = depth(root, 1);
            return d;
        }
}
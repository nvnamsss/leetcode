public class Solution {
    int max;
    public int recursive(TreeNode node, int val)
    {
        if (node == null) return val;

        val += 1;
        int left = val;
        int right = val;

        //max value = branch left + branch right
        //branch value = 

        if (node.left != null) 
        {
            left = recursive(node.left, val);            
        }

        if (node.right != null)
        {
            right = recursive(node.right, val);
        }

        max = Math.Max(max, left + right - 2 * val);
        return Math.Max(left, right);
    }

    public int DiameterOfBinaryTree(TreeNode root) {
        max = 0;
        recursive(root, 0);
        return max;
    }
}
using System;

public class Solution {
    List<int> result;
    public void Preorder(TreeNode root)
    {
        if (root == null) return;
        result.Add(root.val);
        Preorder(root.left);
        Preorder(root.right);
    }
    public IList<int> PreorderTraversal(TreeNode root) {
        result = new List<int>();
        Stack<TreeNode> stack = new Stack<TreeNode>();
        
        if (root == null) return result;
        TreeNode cur = root;
        stack.Push(root);
        while (stack.Count > 0)
        {
            cur = stack.Pop();
            //do here
            result.Add(cur.val);
            if (cur.right != null) stack.Push(cur.right);
            if (cur.left != null) stack.Push(cur.left);
        }
        
        return result;
    }
}
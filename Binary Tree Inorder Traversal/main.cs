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
    public IList<int> InorderTraversal(TreeNode root) {
        List<int> result = new List<int>();
        Stack<TreeNode> stack = new Stack<TreeNode>();
        TreeNode cur = root;
        while (cur != null || stack.Count != 0)
        {
            while (cur != null)
            {
                stack.Push(cur);
                cur = cur.left;
            }

            cur = stack.Peek();
            stack.Pop();
            //print here
            Console.WriteLine($"{cur.val} ");
            result.Add(cur.val);
            cur = cur.right;
        }

        return result;
    }

    public IList<int> PostorderTraversal(TreeNode root)
    {
        List<int> result = new List<int>();
        Stack<TreeNode> stack = new Stack<TreeNode>();
        TreeNode cur = root;
        stack.Push(root);
        while (cur != null || stack.Count == 0)
        {
            cur = stack.Peek();
            while (cur != null)
            {
                stack.Push(cur);
                cur = cur.left;
            }

            cur = stack.Peek();
            stack.Pop();
            //print here
            Console.WriteLine($"{cur.val} ");
            result.Add(cur.val);

            
            if (cur.right != null)
            {
                stack.Push(cur.right);
            }
            cur = cur.right;
        }

        return result;
    }

    public IList<int> PreorderTraversal(TreeNode root)
    {
        List<int> result = new List<int>();
        Stack<TreeNode> stack = new Stack<TreeNode>();
        TreeNode cur = root;
        stack.Push(cur);
        while (stack.Count != 0)
        {
            cur = stack.Pop();
            //pritn here
            Console.WriteLine($"{cur.val} ");
            result.Add(cur.val);
            if (cur.right != null)
            {
                stack.Push(cur.right);
            }

            if (cur.left != null)
            {
                stack.Push(cur.left);
            }
        }

        return result;
    }
}
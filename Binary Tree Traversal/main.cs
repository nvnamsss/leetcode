public class TreeNode
{
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode parent;
    public TreeNode(int val, TreeNode left = null, TreeNode right = null)
    {
        this.val = val;
        this.left = left;
        this.right = right;
    }

    public void Inorder()
    {
        if (left != null)
        {
            left.Inorder();
        }

        Console.WriteLine($"{val} ");

        if (right != null)
        {
            right.Inorder();
        }
    }
}

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
        while (stack.Count != 0)
        {
            cur = stack.Peek();
            while (cur != null)
            {
                if (cur.right != null) stack.Push(cur.right);
                
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
        do {
            while (cur != null)
            {
                if (cur.right != null)
                {
                    stack.Push(cur.right);
                }

                stack.Push(cur);
                cur = cur.left;
            }

            cur = stack.Pop();
            if (cur.right != null && stack.Peek() == cur.right)
            {
                stack.Pop();
                stack.Push(cur);
                cur = cur.right;
            }else{
                result.Add(cur.val);
                cur = null;
            }

        } while (stack.Count != 0);

        return result;
    }
    
    public void PostOrder(TreeNode root)
    {
        if (root.left != null) PostOrder(root.left);

        if (root.right != null) PostOrder(root.right);

        //do stuff here

    }

    public void InOrder(TreeNode root)
    {
        if (root.left != null) PostOrder(root.left);
        //do stuff here
        if (root.right != null) PostOrder(root.right);
    }

    public void PreOrder(TreeNode root)
    {
        //do stuff here
        if (root.left != null) PostOrder(root.left);
        if (root.right != null) PostOrder(root.right);
    }
}
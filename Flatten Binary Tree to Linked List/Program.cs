using System;

namespace Flatten_Binary_Tree_to_Linked_List
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            TreeNode node = example1();
            s.Flatten(node);

            
        }

        static TreeNode example1() {
            TreeNode n1 = new TreeNode(2, new TreeNode(3), new TreeNode(4));
            TreeNode n2 = new TreeNode(5, null, new TreeNode(6));
            TreeNode n = new TreeNode(1, n1, n2);

            return n;
        }
    }
}

using System;
using System.Collections.Generic;

namespace Binary_Tree_Level_Order_Traversal
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            IList<IList<int>> rs =  s.LevelOrder(example1());
            print(rs);
        }

        static TreeNode example1() {
            TreeNode l1 = new TreeNode(9);
            TreeNode r1 = new TreeNode(20, new TreeNode(15), new TreeNode(7));
            TreeNode root = new TreeNode(3, l1, r1);

            return root;
        }

        static void print(IList<IList<int>> rs) {
            for (int loop = 0; loop < rs.Count; loop++)
            {
                Console.Write("[");
                for (int loop2 = 0; loop2 < rs[loop].Count; loop2++)
                {
                    Console.Write($"{rs[loop][loop2]} ");
                }
                Console.Write("],");
            }
            Console.WriteLine();
        }
    }
}

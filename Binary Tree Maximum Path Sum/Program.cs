using System;

namespace Binary_Tree_Maximum_Path_Sum
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int?[] values = new int?[]{5,4,8,11,null,13,4,7,2,null,null,null,1};
            TreeNode node = TreeBuilder.Build(values);
            int rs = s.MaxPathSum(node);
            Console.WriteLine($"Result:{rs} - Expect: {48}");

        }
    }
}

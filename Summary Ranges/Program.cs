using System;
using System.Collections;
using System.Collections.Generic;
namespace Summary_Ranges
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution solution=  new Solution();
            int[] nums = new int[]{0,1,2,4,5,7};
            IList<string> rs = solution.SummaryRanges(nums);
            solution.Print(rs);

            nums= new int[]{0,2,3,4,6,8,9};
            rs = solution.SummaryRanges(nums);
            solution.Print(rs);

            nums = new int[]{};
            rs = solution.SummaryRanges(nums);
            solution.Print(rs);

            nums = new int[]{0};
            rs = solution.SummaryRanges(nums);
            solution.Print(rs);
            
            Console.WriteLine("Hello World!");
        }
    }
}

using System;
using System.Collections.Generic;

namespace Graph_Connectivity_With_Threshold
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution solution= new Solution();
            int n = 6;
            int threshold = 2;
            int[][] queries = new int[][]{new int[]{1,4}, new int[]{2,5}, new int[]{3,6}};
            IList<bool> rs = solution.AreConnected(n, threshold, queries);
            solution.Print(rs);

            n = 5;
            threshold = 1;
            queries = new int[][]{new int[]{4,5}, new int[]{4,5},new int[]{3,2}, new int[] {2, 3}, new int[]{3,4}};
            rs = solution.AreConnected(n, threshold, queries);
            solution.Print(rs);

            Console.WriteLine("Hello World!");
        }
    }
}

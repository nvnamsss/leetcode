using System;

namespace Onsite_Interview
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int[][] prerequisites = new int[][]{
                new int[]{1, 0},
            };
            bool rs = s.CanFinish(2, prerequisites);
            Console.WriteLine($"Result: {rs} - Expect: {true}");
            int[] order = s.FindOrder(2, prerequisites);

            prerequisites = new int[][] {
                new int[]{1, 0},
                new int[]{0, 1},
            };
            rs = s.CanFinish(2, prerequisites);
            Console.WriteLine($"Result: {rs} - Expect: {false}");

            prerequisites = new int[][] {
                new int[]{0, 1},
            };
            rs = s.CanFinish(2, prerequisites);
            Console.WriteLine($"Result: {rs} - Expect: {true}");

            
        }

        static void print(int[] rs) {
            for (int loop = 0; loop < rs.Length; loop++)
            {
                Console.Write($"{rs[loop]} ");
            }
        }
    }
}

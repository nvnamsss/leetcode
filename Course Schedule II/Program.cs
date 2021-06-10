using System;

namespace Course_Schedule_II
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int[] rs = s.FindOrder(2, new int[][]{
                new int[]{1, 0},
            });
            print(rs);

            rs = s.FindOrder(2, new int[][]{
                new int[]{0, 1},
            });
            print(rs);

            rs = s.FindOrder(2, new int[][]{
                new int[]{0, 1},
                new int[]{1, 0},
            });
            print(rs);

            rs = s.FindOrder(4, new int[][]{
                new int[]{1, 0},
                new int[]{2, 0},
                new int[]{3, 1},
                new int[]{3, 2},
            });
            print(rs);

            rs = s.FindOrder(4, new int[][]{
                new int[]{0, 1},
                new int[]{2, 0},
                new int[]{3, 1},
                new int[]{3, 2},
            });
            print(rs);
        }

        static void print(int[] rs)
        {
            for (int loop = 0; loop < rs.Length; loop++)
            {
                Console.Write($"{rs[loop]} ");
            }
            Console.WriteLine();
        }
    }
}

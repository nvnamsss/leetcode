using System;

namespace Course_Schedule_III
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int[][] courses = new int[][]{
                new int[]{100,200},
                new int[]{200,1300},
                new int[]{1000,1250},
                new int[]{2000, 3200},
            };

            int rs = s.ScheduleCourse(courses);
            Console.WriteLine($"Result: {rs} - Expect: {3}");

            courses = new int[][]{
                new int[]{100,200},
                new int[]{200,1300},
                new int[]{1000,1250},
                new int[]{2000, 32000},
            };

            rs = s.ScheduleCourse(courses);
            Console.WriteLine($"Result: {rs} - Expect: {4}");

            courses = new int[][]{
                new int[]{3,2},
                new int[]{4,3},
            };

            rs = s.ScheduleCourse(courses);
            Console.WriteLine($"Result: {rs} - Expect: {0}");

            courses = new int[][]{
                new int[]{3,3},
                new int[]{3,6},
            };

            rs = s.ScheduleCourse(courses);
            Console.WriteLine($"Result: {rs} - Expect: {2}");
        }
    }
}

using System;

namespace Theater
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int rs = s.solution(new int[]{1,2,3,4});
            Console.WriteLine($"Result: {rs} - Expect: {4}");

            rs = s.solution(new int[]{1,2,3,4,5});
            Console.WriteLine($"Result: {rs} - Expect: {10}");

            rs = s.solution(new int[]{1,1,1});
            Console.WriteLine($"Result: {rs} - Expect: {1}");

            rs = s.solution(new int[]{1,1,1,1});
            Console.WriteLine($"Result: {rs} - Expect: {1}");

            rs = s.solution(new int[]{1,2,2,1,2 ,2});
            Console.WriteLine($"Result: {rs} - Expect: {6}");

            rs = s.solution(new int[]{2,2,2,1,2,2});
            Console.WriteLine($"Result: {rs} - Expect: {4}");

            rs = s.solution(new int[]{2,2,1,2,2});
            Console.WriteLine($"Result: {rs} - Expect: {4}");

            rs = s.solution(new int[]{2,1,2,2});
            Console.WriteLine($"Result: {rs} - Expect: {3}");
            // rs = s.solution(new int[]{2,2,2,1,2,2});
            // Console.WriteLine($"Result: {rs} - Expect: {4}");

            // rs = s.solution(new int[]{2,1,2,1,2});
            // Console.WriteLine($"Result: {rs} - Expect: {4}");

            // rs = s.solution(new int[]{2,1,2,3,2});
            // Console.WriteLine($"Result: {rs} - Expect: {4}");

            rs = s.solution(new int[]{1,2,1,1});
            Console.WriteLine($"Result: {rs} - Expect: {3}");
            
            rs = s.solution(new int[]{1,2,3,2});
            Console.WriteLine($"Result: {rs} - Expect: {4}");

            rs = s.solution(consecutive(30));
            Console.WriteLine($"Result: {rs} - Expect: {4060}");
        }

        static int[] consecutive(int N) {
            int[] rs = new int[N];
            for (int loop = 0; loop < N; loop++)
            {
                rs[loop]=loop + 1;
            }

            return rs;
        }
    }
}

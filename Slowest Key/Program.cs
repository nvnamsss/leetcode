using System;

namespace Slowest_Key
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution solution= new Solution();
            int[] times = new int[]{9,29,49,50};
            string pressed = "cbcd";
            char rs  = solution.SlowestKey(times, pressed);
            Console.WriteLine($"Result: {rs} - Expect: {'c'}");
            Console.WriteLine("Hello World!");
        }
    }
}

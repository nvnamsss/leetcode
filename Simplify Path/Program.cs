using System;

namespace Simplify_Path
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            string path= "/b";
            string rs = s.SimplifyPath(path);
            Console.WriteLine($"Result: {rs} - Expect: {"/b"}");

            path = "/../";
            rs = s.SimplifyPath(path);
            Console.WriteLine($"Result: {rs} - Expect: {"/"}");

            path = "/home/";
            rs = s.SimplifyPath(path);
            Console.WriteLine($"Result: {rs} - Expect: {"/home"}");

            path = "/home//foo/";
            rs = s.SimplifyPath(path);
            Console.WriteLine($"Result: {rs} - Expect: {"/home/foo"}");

        }
    }
}

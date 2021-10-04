using System;

namespace _08_01
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            Console.WriteLine($"Result: {s.LicenseKeyFormatting("5F3Z-2e-9-w", 4)}");
            Console.WriteLine($"Result: {s.LicenseKeyFormatting("2-5g-3-J", 2)}");
            Console.WriteLine($"Result: {s.LicenseKeyFormatting("2-4A0r7-4k", 4)}");

            int rs = s.LengthLongestPath("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext");
            Console.WriteLine($"Result: {rs} - Expect: {20}");

            s.InvalidTransactions(new string[]{
               "alice,20,800,mtv","alice,50,1200,mtv"
           });
        }
    }
}

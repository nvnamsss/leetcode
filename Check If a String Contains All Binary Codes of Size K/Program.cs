using System;

namespace Check_If_a_String_Contains_All_Binary_Codes_of_Size_K
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution solution=  new Solution();
            bool rs = solution.HasAllCodes("00110", 2);
            Console.WriteLine($"Result {rs} - Expect: {true}");
        }
    }
}

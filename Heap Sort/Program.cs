using System;

namespace Heap_Sort
{
    class Program
    {
        static void Main(string[] args)
        {
            Heap h = new Heap();
            int[] arr = new int[]{4,1,3,9,7};
            h.Sort(arr);
        }
    }
}

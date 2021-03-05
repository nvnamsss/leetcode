using System;

namespace LFU_Cache
{
    class Program
    {
        static void Main(string[] args)
        {
            LFUCache cache = new LFUCache(3);
            cache.Put(1, 1);
            int rs = cache.Get(1);
            rs = cache.Get(1);
            rs = cache.Get(1);
            Console.WriteLine($"Result: {rs} - Expect: {1}");
            cache.Put(2, 2);
            cache.Put(3, 3);
            cache.Put(4, 4);
            rs = cache.Get(2);
            Console.WriteLine($"Result: {rs} - Expect: {-1}");
            rs = cache.Get(4);
            Console.WriteLine($"Result: {rs} - Expect: {4}");
            rs = cache.Get(4);
            rs = cache.Get(4);
            rs = cache.Get(3);
            Console.WriteLine($"Result: {rs} - Expect: {3}");
            cache.Put(5, 5);
            rs = cache.Get(2);
            Console.WriteLine($"Result: {rs} - Expect: {-1}");
            rs = cache.Get(5);
            Console.WriteLine($"Result: {rs} - Expect: {5}");

            // phase 2

            cache = new LFUCache(1);
            cache.Put(1,1);
            rs=  cache.Get(1);
            Console.WriteLine($"Result: {rs} - Expect: {1}");
            cache.Put(1, 3);
            rs = cache.Get(1);
            Console.WriteLine($"Result: {rs} - Expect: {3}");
            cache.Put(2, 4);
            rs = cache.Get(2);            
            Console.WriteLine($"Result: {rs} - Expect: {4}");
            rs = cache.Get(1);
            Console.WriteLine($"Result: {rs} - Expect: {-1}");

            // phase 3

            cache= new LFUCache(2);
            cache.Put(1,1);
            cache.Put(2,2);
            rs= cache.Get(1);
            Console.WriteLine($"Result: {rs} - Expect: {1}");
            cache.Put(3,3);
            rs = cache.Get(2);
            Console.WriteLine($"Result: {rs} - Expect: {-1}");
            rs = cache.Get(3);
            Console.WriteLine($"Result: {rs} - Expect: {3}");
            cache.Put(4, 4);
            cache.Get(1);
            rs = cache.Get(-1);
            Console.WriteLine($"Result: {rs} - Expect: {-1}");
            rs = cache.Get(3);
            Console.WriteLine($"Result: {rs} - Expect: {3}");
        }
    }
}

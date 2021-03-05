using System;

namespace LRU_Cache
{
    class Program
    {
        static void Main(string[] args)
        {
            LRUCache cache = new LRUCache(2);
            cache.Put(1, 1);
            cache.Put(2, 2);
            int rs = cache.Get(1);
            Console.WriteLine($"Result: {rs} - Expect: {1}");
            cache.Put(3, 3);
            rs = cache.Get(2);
            Console.WriteLine($"Result: {rs} - Expect: {-1}");
            cache.Put(4, 4);
            rs = cache.Get(1);
            Console.WriteLine($"Result: {rs} - Expect: {-1}");
            rs = cache.Get(2);
            Console.WriteLine($"Result: {rs} - Expect: {-1}");
            rs = cache.Get(3);
            Console.WriteLine($"Result: {rs} - Expect: {3}");
            rs = cache.Get(4);
            Console.WriteLine($"Result: {rs} - Expect: {4}");
            
            Console.WriteLine("Phase 2");
            cache = new LRUCache(4);
            cache.Put(1,1);
            cache.Put(2,2);
            cache.Put(3,3);
            cache.Put(4,4);
            cache.Put(5,5);
            rs = cache.Get(1);
            Console.WriteLine($"Result: {rs} - Expect: {-1}");
            rs = cache.Get(2);
            Console.WriteLine($"Result: {rs} - Expect: {2}");
            rs = cache.Get(4);
            Console.WriteLine($"Result: {rs} - Expect: {4}");
            cache.Put(6, 6);
            rs = cache.Get(3);
            Console.WriteLine($"Result: {rs} - Expect: {-1}");
            cache.Put(7, 7);
            rs = cache.Get(7);
            Console.WriteLine($"Result: {rs} - Expect: {7}");
            rs = cache.Get(5);
            Console.WriteLine($"Result: {rs} - Expect: {-1}");

            Console.WriteLine("Phase 3");
            cache = new LRUCache(1);
            cache.Put(1,1);
            cache.Put(2, 2);
            rs = cache.Get(1);
            Console.WriteLine($"Result: {rs} - Expect: {-1}");
            rs = cache.Get(2);
            Console.WriteLine($"Result: {rs} - Expect: {2}");
            cache.Put(3, 3);
            rs = cache.Get(3);
            Console.WriteLine($"Result: {rs} - Expect: {3}");

            Console.WriteLine("Phase 4");
            cache = new LRUCache(2);
            cache.Put(2, 2);
            cache.Put(3, 3);
            rs = cache.Get(3);
            Console.WriteLine($"Result: {rs} - Expect: {3}");
            rs = cache.Get(2);
            Console.WriteLine($"Result: {rs} - Expect: {2}");
            cache.Put(4, 4);
            rs = cache.Get(2);
            Console.WriteLine($"Result: {rs} - Expect: {2}");
            rs = cache.Get(3);
            Console.WriteLine($"Result: {rs} - Expect: {-1}");
        }
    }
}

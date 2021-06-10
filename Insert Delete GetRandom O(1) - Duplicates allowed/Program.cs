using System;

namespace Insert_Delete_GetRandom_O_1____Duplicates_allowed
{
    class Program
    {
        static void Main(string[] args)
        {
            RandomizedCollection collection = new RandomizedCollection();
            int rs;
            bool status;
            
            collection.Insert(1);
            collection.Insert(1);
            collection.Insert(2);
            collection.Insert(1);
            collection.Insert(2);
            collection.Insert(2);

            status = collection.Remove(1);
            Console.WriteLine($"Status: {status}");
            status = collection.Remove(2);
            Console.WriteLine($"Status: {status}");
            status = collection.Remove(2);
            Console.WriteLine($"Status: {status}");
            status = collection.Remove(2);
            Console.WriteLine($"Status: {status}");
            collection.GetRandom();
        }
    }
}

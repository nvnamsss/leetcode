using System;
using System.Collections.Generic;

namespace Keys_and_Rooms
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            IList<IList<int>> rooms = new List<IList<int>>();
            rooms.Add(new List<int>(){1});
            rooms.Add(new List<int>(){2});
            rooms.Add(new List<int>(){3});
            rooms.Add(new List<int>(){});
            bool rs = s.CanVisitAllRooms(rooms);
            Console.WriteLine($"Result: {rs} - Expect: {true}");

            rooms = new List<IList<int>>();
            rooms.Add(new List<int>(){1, 3});
            rooms.Add(new List<int>(){3,0, 1});
            rooms.Add(new List<int>(){2});
            rooms.Add(new List<int>(){0});
            rs = s.CanVisitAllRooms(rooms);
            Console.WriteLine($"Result: {rs} - Expect: {false}");

            rooms = new List<IList<int>>();
            rooms.Add(new List<int>(){1});
            rooms.Add(new List<int>(){4});
            rooms.Add(new List<int>(){3});
            rooms.Add(new List<int>(){2});
            rooms.Add(new List<int>(){});
             rs = s.CanVisitAllRooms(rooms);
            Console.WriteLine($"Result: {rs} - Expect: {false}");
        }
    }
}

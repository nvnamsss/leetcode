using System;

namespace Populating_Next_Right_Pointers_in_Each_Node
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            Node node = new Node(1);
            Node n2 = new Node(2, new Node(4), new Node(5), null);
            Node n3 = new Node(3, new Node(6), new Node(7), null);
            node.left = n2;
            node.right = n3;

            s.Connect(node);
            Console.WriteLine("Hello World!");
        }
    }
}

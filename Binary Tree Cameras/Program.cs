using System;

namespace Binary_Tree_Cameras
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int rs = s.MinCameraCover(example1());
            Console.WriteLine($"Result: {rs} - Expect: {1}");

            rs = s.MinCameraCover(example2());
            Console.WriteLine($"Result: {rs} - Expect: {2}");

            rs = s.MinCameraCover(example3());
            Console.WriteLine($"Result: {rs} - Expect: {2}");

            rs = s.MinCameraCover(example4());
            Console.WriteLine($"Result: {rs} - Expect: {3}");

            rs = s.MinCameraCover(example5());
            Console.WriteLine($"Result: {rs} - Expect: {1}");

            rs = s.MinCameraCover(example6());
            Console.WriteLine($"Result: {rs} - Expect: {1}");

                        rs = s.MinCameraCover(example7());
            Console.WriteLine($"Result: {rs} - Expect: {1}");
        }

        static TreeNode example1()
        {
            TreeNode n1 = new TreeNode(0, new TreeNode(0), new TreeNode(0));
            TreeNode n = new TreeNode(0, n1);

            return n;
        }

        static TreeNode example2()
        {
            TreeNode n1 = new TreeNode(0, new TreeNode(0), new TreeNode(0));
            TreeNode n2 = new TreeNode(0, new TreeNode(0), new TreeNode(0));
            TreeNode n = new TreeNode(0, n1, n2);

            return n;
        }

        static TreeNode example3()
        {
            TreeNode n5 = new TreeNode(0);
            TreeNode n4 = new TreeNode(0, null, n5);
            TreeNode n3 = new TreeNode(0, n4);
            TreeNode n2 = new TreeNode(0, n3);
            TreeNode n1 = new TreeNode(0, n2);

            return n1;
        }

        static TreeNode example4()
        {
            TreeNode n5 = new TreeNode(0, new TreeNode());
            TreeNode n6 = new TreeNode(0, null, new TreeNode());

            TreeNode n4 = new TreeNode(0, n5, n6);

            TreeNode n3 = new TreeNode(0, n4);

            TreeNode n2 = new TreeNode(0);
            TreeNode n1 = new TreeNode(0, n2, n3);

            return n1;
        }

        static TreeNode example5()
        {
            TreeNode n = new TreeNode(0);

            return n;
        }

        static TreeNode example6()
        {
            TreeNode n = new TreeNode(0, new TreeNode(0));
            return n;
        }

                static TreeNode example7()
        {
            TreeNode n = new TreeNode(0, new TreeNode(0), new TreeNode(0));
            return n;
        }
    }
}

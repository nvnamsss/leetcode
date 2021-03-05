using System;

namespace Remove_Duplicates_from_Sorted_List_II
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            ListNode head = Create(new int[] { 1, 2, 3, 3, 4, 4, 5 });
            head = s.DeleteDuplicates(head);
            Print(head);

            head = Create(new int[] { 1, 1, 1, 2, 3 });
            head = s.DeleteDuplicates(head);
            Print(head);

            head = Create(new int[] { 1, 1, 1, 2, 2, 3 });
            head = s.DeleteDuplicates(head);
            Print(head);

            head = null;
            head = s.DeleteDuplicates(head);
            Print(head);

        }

        static ListNode Create(int[] array)
        {
            ListNode head = new ListNode(array[0]);
            ListNode cur = head;
            for (int loop = 1; loop < array.Length; loop++)
            {
                cur.next = new ListNode(array[loop]);
                cur = cur.next;
            }

            return head;
        }

        static void Print(ListNode head)
        {
            ListNode cur = head;
            while (cur != null)
            {
                Console.Write($"{cur.val}\t");
                cur = cur.next;
            }

            Console.WriteLine();
        }
    }
}

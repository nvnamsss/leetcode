/*
Given an array of integers arr, you are initially positioned at the first index of the array.

In one step you can jump from index i to index:

i + 1 where: i + 1 < arr.length.
i - 1 where: i - 1 >= 0.
j where: arr[i] == arr[j] and i != j.
Return the minimum number of steps to reach the last index of the array.

Notice that you can not jump outside of the array at any time.

 

Example 1:

Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
Output: 3
Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
Example 2:

Input: arr = [7]
Output: 0
Explanation: Start index is the last index. You don't need to jump.
Example 3:

Input: arr = [7,6,9,6,9,6,9,7]
Output: 1
Explanation: You can jump directly from index 0 to index 7 which is last index of the array.
Example 4:

Input: arr = [6,1,9]
Output: 2
Example 5:

Input: arr = [11,22,7,7,7,7,7,7,7,22,13]
Output: 3
 

Constraints:

1 <= arr.length <= 5 * 10^4
-10^8 <= arr[i] <= 10^8
*/

using System;
using System.Collections.Generic;
public class Solution
{
    public int MinJumps(int[] arr)
    {
        Dictionary<int, List<int>> g = new Dictionary<int, List<int>>();
        int[][] edges = new int[arr.Length][];
        bool[] visited = new bool[arr.Length];

        for (int loop = 0; loop < arr.Length; loop++)
        {
            if (!g.ContainsKey(arr[loop]))
            {
                g.Add(arr[loop], new List<int>());
            }
            g[arr[loop]].Add(loop);
        }

        int result = 0;
        Queue<int> q = new Queue<int>();
        q.Enqueue(0);
        while (true)
        {
            int count = q.Count;

            for (int loop = 0; loop < count; loop++)
            {
                int index = q.Dequeue();
                if (index == arr.Length - 1) return result;
                if (visited[index]) continue;
                visited[index] = true;
                q.Enqueue(index + 1);
                if (index > 0) q.Enqueue(index - 1);
                if (g.ContainsKey(arr[index]))
                {
                    foreach (var item in g[arr[index]])
                    {
                        q.Enqueue(item);
                    }
                    g.Remove(arr[index]);
                }

            }

            result++;
        }
    }

    private bool visit(bool[] visited, Queue<int> q, int index)
    {
        if (visited[index]) return true;
        q.Enqueue(index);
        visited[index] = true;
        return false;
    }
}
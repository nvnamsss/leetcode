/*
You are given an integer array heights representing the heights of buildings, some bricks, and some ladders.

You start your journey from building 0 and move to the next building by possibly using bricks or ladders.

While moving from building i to building i+1 (0-indexed),

If the current building's height is greater than or equal to the next building's height, you do not need a ladder or bricks.
If the current building's height is less than the next building's height, you can either use one ladder or (h[i+1] - h[i]) bricks.
Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally.

 

Example 1:


Input: heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1
Output: 4
Explanation: Starting at building 0, you can follow these steps:
- Go to building 1 without using ladders nor bricks since 4 >= 2.
- Go to building 2 using 5 bricks. You must use either bricks or ladders because 2 < 7.
- Go to building 3 without using ladders nor bricks since 7 >= 6.
- Go to building 4 using your only ladder. You must use either bricks or ladders because 6 < 9.
It is impossible to go beyond building 4 because you do not have any more bricks or ladders.
Example 2:

Input: heights = [4,12,2,7,3,18,20,3,19], bricks = 10, ladders = 2
Output: 7
Example 3:

Input: heights = [14,3,19,3], bricks = 17, ladders = 0
Output: 3
 

Constraints:

1 <= heights.length <= 105
1 <= heights[i] <= 106
0 <= bricks <= 109
0 <= ladders <= heights.length
*/

using System;
using System.Collections.Generic;
public class PriorityQueue<T>
{
    class Node
    {
        public int Priority { get; set; }
        public T Object { get; set; }
    }

    //object array
    List<Node> queue = new List<Node>();
    int heapSize = -1;
    bool _isMinPriorityQueue;
    public int Count { get { return queue.Count; } }

    /// <summary>
    /// If min queue or max queue
    /// </summary>
    /// <param name="isMinPriorityQueue"></param>
    public PriorityQueue(bool isMinPriorityQueue = false)
    {
        _isMinPriorityQueue = isMinPriorityQueue;
    }


    public void Enqueue(int priority, T obj)
    {
        Node node = new Node() { Priority = priority, Object = obj };
        queue.Add(node);
        heapSize++;
        //Maintaining heap
        if (_isMinPriorityQueue)
            BuildHeapMin(heapSize);
        else
            BuildHeapMax(heapSize);
    }
    public T Dequeue()
    {
        if (heapSize > -1)
        {
            var returnVal = queue[0].Object;
            queue[0] = queue[heapSize];
            queue.RemoveAt(heapSize);
            heapSize--;
            //Maintaining lowest or highest at root based on min or max queue
            if (_isMinPriorityQueue)
                MinHeapify(0);
            else
                MaxHeapify(0);
            return returnVal;
        }
        else
            throw new Exception("Queue is empty");
    }
    public void UpdatePriority(T obj, int priority)
    {
        int i = 0;
        for (; i <= heapSize; i++)
        {
            Node node = queue[i];
            if (object.ReferenceEquals(node.Object, obj))
            {
                node.Priority = priority;
                if (_isMinPriorityQueue)
                {
                    BuildHeapMin(i);
                    MinHeapify(i);
                }
                else
                {
                    BuildHeapMax(i);
                    MaxHeapify(i);
                }
            }
        }
    }
    public bool IsInQueue(T obj)
    {
        foreach (Node node in queue)
            if (object.ReferenceEquals(node.Object, obj))
                return true;
        return false;
    }

    private void BuildHeapMax(int i)
    {
        while (i >= 0 && queue[(i - 1) / 2].Priority < queue[i].Priority)
        {
            Swap(i, (i - 1) / 2);
            i = (i - 1) / 2;
        }
    }
    private void BuildHeapMin(int i)
    {
        while (i >= 0 && queue[(i - 1) / 2].Priority > queue[i].Priority)
        {
            Swap(i, (i - 1) / 2);
            i = (i - 1) / 2;
        }
    }
    private void MaxHeapify(int i)
    {
        int left = ChildL(i);
        int right = ChildR(i);

        int heighst = i;

        if (left <= heapSize && queue[heighst].Priority < queue[left].Priority)
            heighst = left;
        if (right <= heapSize && queue[heighst].Priority < queue[right].Priority)
            heighst = right;

        if (heighst != i)
        {
            Swap(heighst, i);
            MaxHeapify(heighst);
        }
    }
    private void MinHeapify(int i)
    {
        int left = ChildL(i);
        int right = ChildR(i);

        int lowest = i;

        if (left <= heapSize && queue[lowest].Priority > queue[left].Priority)
            lowest = left;
        if (right <= heapSize && queue[lowest].Priority > queue[right].Priority)
            lowest = right;

        if (lowest != i)
        {
            Swap(lowest, i);
            MinHeapify(lowest);
        }
    }

    private void Swap(int i, int j)
    {
        var temp = queue[i];
        queue[i] = queue[j];
        queue[j] = temp;
    }
    private int ChildL(int i)
    {
        return i * 2 + 1;
    }
    private int ChildR(int i)
    {
        return i * 2 + 2;
    }
}

public class Solution
{
    public int FurthestBuilding(int[] heights, int bricks, int ladders)
    {
        PriorityQueue<int> queue = new PriorityQueue<int>();
        for (int loop = 0; loop < heights.Length - 1; loop++)
        {
            if (heights[loop] >= heights[loop + 1]) continue;
            int dif = heights[loop + 1] - heights[loop];
            if (bricks >= dif)
            {
                bricks -= dif;
                queue.Enqueue(dif, dif);
            }  else {
                if (ladders == 0) return loop;
                
                ladders -= 1;
                if (queue.Count > 0)
                {
                    bricks += queue.Dequeue();
                    bricks -= dif;
                }
            }
        }

        return heights.Length - 1;
    }
}
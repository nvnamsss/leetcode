/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * interface NestedInteger {
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool IsInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     int GetInteger();
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     IList<NestedInteger> GetList();
 * }
 */

using System;
using System.Collections.Generic;

public interface NestedInteger
{
    bool IsInteger();
    int GetInteger();
    IList<NestedInteger> GetList();
}

public class NestedIterator
{

    IList<NestedInteger> list;
    int index;
    Queue<NestedInteger> queue;
    public NestedIterator(IList<NestedInteger> nestedList)
    {
        list = nestedList;
        queue = new Queue<NestedInteger>();
        if (nestedList.Count > 0)
        {
            IList<NestedInteger> sublist;
            if (queue.Count == 0)
            {
                sublist = list[index].GetList();
                Console.WriteLine($"Sublist length: {sublist.Count}");
                for (int loop = 0; loop < sublist.Count; loop++)
                {
                    queue.Enqueue(sublist[loop]);
                }

                if (sublist.Count == 0 && list[index].IsInteger()) queue.Enqueue(list[index]);
                index++;
            }
        }
    }

    public bool HasNext()
    {
        return index < list.Count || queue.Count > 0;
    }

    public int Next()
    {
        IList<NestedInteger> sublist;
        if (queue.Count == 0)
        {
            sublist = list[index].GetList();
            Console.WriteLine($"Sublist length: {sublist.Count}");
            for (int loop = 0; loop < sublist.Count; loop++)
            {
                queue.Enqueue(sublist[loop]);
            }

            if (sublist.Count == 0 && list[index].IsInteger()) queue.Enqueue(list[index]);
            index++;
        }

        NestedInteger ni = queue.Dequeue();
        while (!ni.IsInteger())
        {
            sublist = ni.GetList();
            for (int loop = 0; loop < sublist.Count; loop++)
            {
                queue.Enqueue(sublist[loop]);
            }
            ni = queue.Dequeue();
        }

        int value = ni.GetInteger();

        return value;
    }
}

/**
 * Your NestedIterator will be called like this:
 * NestedIterator i = new NestedIterator(nestedList);
 * while (i.HasNext()) v[f()] = i.Next();
 */
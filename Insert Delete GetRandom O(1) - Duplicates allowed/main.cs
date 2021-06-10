using System;
using System.Collections.Generic;
using System.Linq;

public class RandomizedCollection
{
    Random random;
    List<int> array;
    Dictionary<int, HashSet<int>> map;
    /** Initialize your data structure here. */
    public RandomizedCollection()
    {
        random = new Random();
        array = new List<int>();
        map = new Dictionary<int, HashSet<int>>();
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    public bool Insert(int val)
    {
        bool ret = false;
        if (!map.ContainsKey(val))
        {
            map.Add(val, new HashSet<int>());
            ret = true;
        }

        array.Add(val);
        map[val].Add(array.Count - 1);
        return ret;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    public bool Remove(int val)
    {
        if (array.Count == 0) return false;
        if (!map.ContainsKey(val)) return false;
        int last = array.Count - 1;

        HashSet<int> removeSet = map[val];
        HashSet<int> lastSet = map[array[last]];

        int first = removeSet.First();
        int removeIndex = last;
        // swap
        if (array[first] != array[last])
        {

            int tmp = array[last];
            array[last] = array[first];
            array[first] = tmp;
            lastSet.Remove(last);
            lastSet.Add(first);
            removeIndex = first;
        }

        removeSet.Remove(removeIndex);
        if (removeSet.Count == 0) map.Remove(val);
        array.RemoveAt(last);

        return true;
    }

    /** Get a random element from the collection. */
    public int GetRandom()
    {
        int index = random.Next(0, array.Count);
        return array[index];
    }
}

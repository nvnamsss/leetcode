/*
Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack.

Implement the FreqStack class:

FreqStack() constructs an empty frequency stack.
void push(int val) pushes an integer val onto the top of the stack.
int pop() removes and returns the most frequent element in the stack.
If there is a tie for the most frequent element, the element closest to the stack's top is removed and returned.
 

Example 1:

Input
["FreqStack", "push", "push", "push", "push", "push", "push", "pop", "pop", "pop", "pop"]
[[], [5], [7], [5], [7], [4], [5], [], [], [], []]
Output
[null, null, null, null, null, null, null, 5, 7, 5, 4]

Explanation
FreqStack freqStack = new FreqStack();
freqStack.push(5); // The stack is [5]
freqStack.push(7); // The stack is [5,7]
freqStack.push(5); // The stack is [5,7,5]
freqStack.push(7); // The stack is [5,7,5,7]
freqStack.push(4); // The stack is [5,7,5,7,4]
freqStack.push(5); // The stack is [5,7,5,7,4,5]
freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].
freqStack.pop();   // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4].
freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,4].
freqStack.pop();   // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. The stack becomes [5,7].
 

Constraints:

0 <= val <= 109
At most 2 * 104 calls will be made to push and pop.
It is guaranteed that there will be at least one element in the stack before calling pop.
*/

using System;
using System.Collections.Generic;

public class FreqStack
{
    Dictionary<int, int> frequencies;
    Dictionary<int, Stack<int>> values;
    int maxFreq;
    public FreqStack()
    {
        frequencies = new Dictionary<int, int>();
        values = new Dictionary<int, Stack<int>>();
        maxFreq = 0;
    }

    public void Push(int x)
    {
        if (!frequencies.ContainsKey(x)) {
            frequencies.Add(x, 0);
        }
        frequencies[x]++;
        maxFreq = Math.Max(maxFreq, frequencies[x]);

        Stack<int> stack;
        if (!values.ContainsKey(frequencies[x]))
        {
            stack = new Stack<int>();
            values[frequencies[x]] = stack;
        }

        values[frequencies[x]].Push(x);
    }

    public int Pop()
    {

        int ret = values[maxFreq].Pop();
        frequencies[ret]--;
        if (values[maxFreq].Count == 0)
        {
            values.Remove(maxFreq);
            maxFreq--;
        }

        return ret;
    }
}

// public class FreqStack
// {
//     class holder
//     {
//         public int Count => indices.Count;
//         public int val;
//         Stack<int> indices;
//         public holder(int val)
//         {
//             this.val = val;
//             indices = new Stack<int>();
//         }

//         public void push(int index)
//         {
//             indices.Push(index);
//             // indices.Add(index);
//         }

//         public int pop()
//         {
//             return indices.Pop();
//             // indices.RemoveAt(indices.Count - 1);
//         }

//         public int peek()
//         {
//             return indices.Peek();
//         }
//     }

//     Dictionary<int, int> map;
//     List<holder> holders;
//     List<int> arr;
//     public FreqStack()
//     {
//         map = new Dictionary<int, int>();
//         holders = new List<holder>();
//         arr = new List<int>();
//     }

//     public void Push(int val)
//     {
//         arr.Add(val);
//         if (!map.ContainsKey(val))
//         {
//             holders.Add(new holder(val));
//             map.Add(val, holders.Count - 1);
//         }

//         int index = map[val];
//         holders[index].push(arr.Count - 1);

//         heapify((index - 1) / 2);
//     }

//     public int Pop()
//     {
//         int val = arr[holders[0].pop()];

//         heapify(0);
//         int index = map[val];
//         if (holders[index].Count == 0) {
//             holders.RemoveAt(index);
//             map.Remove(val);
//         }

//         return val;
//     }

//     private void heapify(int i)
//     {
//         int n = holders.Count;
//         int left = i * 2 + 1;
//         int right = i * 2 + 2;

//         int largest = i;
//         holder hi = holders[largest];

//         if (left < n)
//         {
//             holder h = holders[left];
//             if (hi.Count < h.Count || (hi.Count > 0 && hi.Count == h.Count && hi.peek() < h.peek()))
//             {
//                 largest = left;
//             }
//         }

//         hi = holders[largest];
//         if (right < n)
//         {
//             holder h = holders[right];
//             if (hi.Count < h.Count || (hi.Count > 0 && hi.Count == h.Count && hi.peek() < h.peek()))
//             {
//                 largest = right;
//             }

//         }
//         if (largest != i)
//         {
//             map[holders[i].val] = largest;
//             map[holders[largest].val] = i;

//             holder tmp = holders[i];
//             holders[i] = holders[largest];
//             holders[largest] = tmp;

//             heapify(largest);
//             heapify((i - 1) / 2);
//         }
//     }

// }

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.Push(val);
 * int param_2 = obj.Pop();
 */
/*
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

For example,
[2,3,4], the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
 

Example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
 

Follow up:

If all integer numbers from the stream are between 0 and 100, how would you optimize it?
If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?
*/

using System;
using System.Collections;
public class MedianFinder {
    List<int> arr;
    /** initialize your data structure here. */
    public MedianFinder() {
        arr = new List<int>();
    }
    
    private int BinarySearch(int l, int r, int value)
    {
        if (r >= l)
        {
            int mid = l + (r - l) / 2;
            if (arr[mid] == value) return mid;
            if (arr[mid] > value) return BinarySearch(l, mid - 1, value);

            return BinarySearch(mid + 1, r, value);
        }

        return ~l;
    }

    public void AddNum(int num) {
          int index = BinarySearch(0, arr.Count - 1, num);
            if (index < 0) index = ~index;

            arr.Insert(index, num);
    }
    
    public double FindMedian() {
            int index = arr.Count / 2;
        if (arr.Count % 2 == 0)
        {
            return (arr[index] + arr[index + 1]) / 2;
        }

        return arr[index];
    }
}

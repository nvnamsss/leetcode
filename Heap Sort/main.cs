/*
Given an array of size N. The task is to sort the array elements by completing functions heapify() and buildHeap() which are used to implement Heap Sort.

Example 1:

Input:
N = 5
arr[] = {4,1,3,9,7}
Output:1 3 4 7 9
Explanation:After sorting elements
using heap sort, elements will be
in order as 1,3,4,7,9.
Example 2:

Input:
N = 10
arr[] = {10,9,8,7,6,5,4,3,2,1}
Output:1 2 3 4 5 6 7 8 9 10
Explanation:After sorting elements
using heap sort, elements will be
in order as 1, 2,3,4,5,6,7,8,9,10.
Your Task :
Complete the functions heapify() and buildheap().

Expected Time Complexity: O(N * Log(N)).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 106
1 <= arr[i] <= 106
*/

/*
    We have 3 steps to do with heap sort
    - Move the max value (value at index 0) of the array to the end of the array 
    - Reduce the size of the array by 1 (implicitly remove the last max value out of the array)
    - Do the heapify (find the next max value)
    
    What does it mean? The Heap sort are based on the characteristic of Heap: "after heapify we ensure that max value are always in the first index"
    Then depends of this characteristic, we keep finding the kth value of the array and push in to the end. 
    So on, after n process we got a sorted array in ascending.

    For descending sorted array, instead of max value, we find the min value of the array then push it to the end thus Min Heap will be applied.
*/
using System;
using System.Collections.Generic;
public class Heap {
    public void Print(int[] arr ) {
        for (int loop = 0; loop < arr.Length; loop++)
        {
            Console.Write($"{arr[loop]}\t");
        }
        Console.WriteLine();
    } 
    public void Sort(int[] arr) {
        buildHeap(arr);
        for (int loop = arr.Length - 1; loop >= 0 ; loop--)
        {
            swap(arr, 0,loop);
            heapify(arr, loop, 0);
        }
        Print(arr);
    }

    private void swap(int[] arr, int a, int b) {
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }

    private void heapify(int[] arr, int n, int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;
        if (left < n && arr[left] > arr[largest]) largest = left;
        if (right < n && arr[right] > arr[largest]) largest = right;
        if (largest != i) {
            swap(arr, i, largest);
            heapify(arr, n, largest);
        }
    }

    private void buildHeap(int[] arr) {
        for (int loop = (int)Math.Floor(arr.Length / 2.0); loop >= 0; loop--)
        {
            heapify(arr, arr.Length, loop);
        }
    }
}

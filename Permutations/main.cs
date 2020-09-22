/*
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/
using System;
using System.Collections;
using System.Collections.Generic;
public class Solution
{
    List<int> p;
    IList<IList<int>> res;
    public int Factorial(int n)
    {
        if (n == 0) return 1;

        int rs = 1;
        for (int loop = 1; loop < n; loop++)
        {
            rs *= loop;
        }

        return rs;
    }
    public static void Swap<T>(T[] arr, int index1, int index2)
    {
        T temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }

    private void Permute(int[] nums, int l, int r)
    {
        if (p.Count == nums.Length)
        {
            res.Add(new List<int>(p));
        }
        else
        {
            for (int loop = l; loop < r; loop++)
            {
                Swap(nums, l, loop);
                p.Add(nums[l]);
                // Swap(nums, l, loop);
                Permute(nums, l + 1, r);
                p.RemoveAt(p.Count - 1);

                Swap(nums, l, loop);
            }
        }
    }

    public IList<IList<int>> Permute(int[] nums)
    {
        p = new List<int>();
        res = new List<IList<int>>();
        if (nums.Length == 0) return res;

        Permute(nums, 0, nums.Length);

        return res;
    }
    public static void IncreaseSelectionSort(int[] nums)
    {
        for (int loop = 0; loop < nums.Length; loop++)
        {
            for (int loop2 = loop; loop2 < nums.Length; loop2++)
            {
                if (nums[loop2] < nums[loop]) Swap(nums[loop], nums[loop2]);
            }
        }
    }

    private bool ShouldSwap(int[] nums, int start, int curr)
    {
        for (int loop = start; loop < curr; loop++)
        {
            if (nums[loop] == nums[curr]) return false;   
        }
         return true;
    }
    private void PermuteUnique(int[] nums, int l, int r)
    {
        if (l == nums.Length)
        {
            res.Add(new List<int>(nums));
            return;
        }

        for (int loop = l; loop < nums.Length; loop++)
        {
            if (loop == l || nums[loop] != nums[l])
            {
                if ((ShouldSwap(nums, l, loop)))
                {
                    Swap(nums, loop, l);
                    PermuteUnique(nums, l + 1, r);
                    Swap(nums, loop, l);
                }

            }
        }
    }
    public IList<IList<int>> PermuteUnique(int[] nums)
    {
        res = new List<IList<int>>();
        PermuteUnique(nums, 0, nums.Length);
        return res;
    }
}

// void fn(vector<int>& nums,int l, int r){

//     if(p.size()==nums.size()){
//         v.push_back(p);
//     }
//     for(int i=l;i<r;i++){
//         swap(nums[l],nums[i]);
//         p.push_back(nums[l]);

//         fn(nums,l+1,r);

//         p.pop_back();
//         swap(nums[l],nums[i]);
//     }
// }
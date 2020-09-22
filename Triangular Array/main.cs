public class Solution
{
    public bool Triangular(int[] arr)
    {
        bool inc = true;
        int c;
        int l;
        for (int loop = 0; loop < arr.Length - 1; loop++)
        {
            if (arr[loop] == arr[loop + 1]) return false;
            if (inc)
            {
                if (arr[loop] > arr[loop + 1])
                {
                    inc = false;
                    l = loop;
                }
            }
            else {
                if (arr[loop] > arr[loop + 1]) return false;
                while (last >= 0 && arr[last] >= arr[loop])
                {
                    if (arr[last] == arr[loop]) return false;
                    last--;
                }
            }
        } 

        return !inc;
    }

}
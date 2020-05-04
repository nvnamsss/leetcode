using System;

// Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

// Note that after backspacing an empty text, the text will continue empty.

// Example 1:

// Input: S = "ab#c", T = "ad#c"
// Output: true
// Explanation: Both S and T become "ac".
// Example 2:

// Input: S = "ab##", T = "c#d#"
// Output: true
// Explanation: Both S and T become "".
// Example 3:

// Input: S = "a##c", T = "#a#c"
// Output: true
// Explanation: Both S and T become "c".
// Example 4:

// Input: S = "a#c", T = "b"
// Output: false
// Explanation: S becomes "c" while T becomes "b".
// Note:

// 1 <= S.length <= 200
// 1 <= T.length <= 200
// S and T only contain lowercase letters and '#' characters.
// Follow up:

// Can you solve it in O(N) time and O(1) space?

public class Solution
{
    public string Backward(string s, int index)
    {
        if (index > 0)
        {
            return s.Remove(index - 1, 2);
        }
        else
        {
            return s.Remove(index, 1);
        }
    }

    public bool BackspaceCompare(string S, string T)
    {
        int length = S.Length;
        for (int loop = 0; loop < S.Length; loop++)
        {
            if (S[loop] == '#')
            {
                S = Backward(S, loop);
                loop -= (length - S.Length);
                length = S.Length;
            }
        }
        
        length = T.Length;
        for (int loop = 0; loop < T.Length; loop++)
        {
            if (T[loop] == '#')
            {
                T = Backward(T, loop);
                loop -= (length - T.Length);
                length = T.Length;
            }
        }

        return S == T;
    }
}
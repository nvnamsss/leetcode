// Given a string, find the length of the longest substring without repeating characters.

// Example 1:

// Input: "abcabcbb"
// Output: 3 
// Explanation: The answer is "abc", with the length of 3. 
// Example 2:

// Input: "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3. 
//              Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

public class Solution
{
    public int LengthOfLongestSubstring(string s)
    {
        int longest = 0;
        int milestone = 0;
        Dictionary<char, int> dictionary = new Dictionary<char, int>();
        for (int loop = 0; loop < s.Length; loop++)
        {
            if (dictionary.ContainsKey(s[loop]))
            {
                milestone = Math.Max(dictionary[s[loop]], milestone);
                dictionary.Remove(s[loop]);
            }
            dictionary.Add(s[loop], loop + 1);

            longest = Math.Max(longest, loop - milestone + 1);
        }
        return longest;
    }
}
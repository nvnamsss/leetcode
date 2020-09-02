using System;
// Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

// Each letter in the magazine string can only be used once in your ransom note.

// Note:
// You may assume that both strings contain only lowercase letters.

// canConstruct("a", "b") -> false
// canConstruct("aa", "ab") -> false
// canConstruct("aa", "aab") -> true

public class Solution {
    public bool CanConstruct(string ransomNote, string magazine) {
        // if (ransomNote.Length == 0) return true;
        int[] chars = new int[26];

for (int loop = 0; loop < magazine.Length; loop++)
        {
            chars[magazine[loop] - 97] += 1;
        }

        for (int loop = 0; loop < ransomNote.Length; loop++)
        {
            chars[ransomNote[loop] - 97] -= 1;
            if (chars[ransomNote[loop] - 97] < 0) return false;
        }        
        
        

        return true;
    }
}   
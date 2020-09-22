/*
A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)

The rules of Goat Latin are as follows:

If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
For example, the word 'apple' becomes 'applema'.
 
If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
For example, the word "goat" becomes "oatgma".
 
Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
Return the final sentence representing the conversion from S to Goat Latin. 

 

Example 1:

Input: "I speak Goat Latin"
Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
Example 2:

Input: "The quick brown fox jumped over the lazy dog"
Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
 

Notes:

S contains only uppercase, lowercase and spaces. Exactly one space between each word.
1 <= S.length <= 150.
*/
using System;
using System.Collections.Generic;

public class Solution {
    HashSet<char> vowels;
    private string goat(string s)
    {
        string rs = s;

        if (vowels.Contains(char.ToLowerInvariant(s[0])))
        {
            rs += "ma";
        }
        else{
            rs += rs[0];
            rs = rs.Remove(0, 1);
            rs += "ma";
        }

        return rs;
    }

    private void init()
    {
        vowels = new HashSet<char>();
        vowels.Add('a');
        vowels.Add('e');
        vowels.Add('i');
        vowels.Add('o');
        vowels.Add('u');
    }

    public string ToGoatLatin(string S) {
        init();
        string result = string.Empty;
        string[] words= S.Split(' ', StringSplitOptions.RemoveEmptyEntries);
        for (int loop = 0; loop < words.Length; loop++)
        {
            string s = goat(words[loop]);
            s += new string('a', loop + 1);

            result += s + " ";
        }
        result = result.TrimEnd();

        return result;
    }
}
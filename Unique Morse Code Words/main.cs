/*
International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows: "a" maps to ".-", "b" maps to "-...", "c" maps to "-.-.", and so on.

For convenience, the full table for the 26 letters of the English alphabet is given below:

[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
Now, given a list of words, each word can be written as a concatenation of the Morse code of each letter. For example, "cab" can be written as "-.-..--...", (which is the concatenation "-.-." + ".-" + "-..."). We'll call such a concatenation, the transformation of a word.

Return the number of different transformations among all words we have.

Example:
Input: words = ["gin", "zen", "gig", "msg"]
Output: 2
Explanation: 
The transformation of each word is:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."

There are 2 different transformations, "--...-." and "--...--.".
Note:

The length of words will be at most 100.
Each words[i] will have length in range [1, 12].
words[i] will only consist of lowercase letters.
*/

using System;
using System.Collections.Generic;

class Solution {
    private int index(char c)
    {
        return char.ToLowerInvariant(c) - 97;
    }

    public int UniqueMorseRepresentations(string[] words) {
        List<string> codes = new List<string>(){".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        HashSet<string> unique = new HashSet<string>();
        
        for (int loop = 0; loop < words.Length; loop++)
        {
            string morse = string.Empty;
            for (int loop2 = 0; loop2 < words[loop].Length; loop2++)
            {
                morse += codes[index(words[loop][loop2])];
            }    

            if (!unique.Contains(morse))
            {
                unique.Add(morse);
            }
        }

        return unique.Count;
    }
}
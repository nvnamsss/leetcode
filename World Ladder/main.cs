/*
Given two words beginWord and endWord, and a dictionary wordList, return the length of the shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list.
Return 0 if there is no such transformation sequence.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog", return its length 5.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
 

Constraints:

1 <= beginWord.length <= 100
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the strings in wordList are unique.
*/

using System;
using System.Text;
using System.Collections.Generic;

public class Solution
{

    public List<string> Gen(string s1, string s2)
    {
        List<string> ss = new List<string>();
        StringBuilder sb = new StringBuilder();
        sb.Append(s1);

        for (int loop = 0; loop < s1.Length; loop++)
        {
            if (s1[loop] != s2[loop])
            {
                sb[loop] = s2[loop];
                ss.Add(sb.ToString());
                sb[loop] = s1[loop];
            }
        }
        return ss;
    }

    private List<string> Gen2(string s1, HashSet<string> s2, HashSet<string> visited)
    {
        List<string> ss = new List<string>();
        foreach (string item in s2)
        {
            if (!visited.Contains(item) && CanTransform(s1, item)) {
                ss.Add(item);
                visited.Add(item);
            }
        }

        return ss;
    }

    private bool CanTransform(string source, string to)
    {
        // A ways to merge two string that 
        // Merge(a, b) = Merge(b, a)
        // evaluate the possibility of this method
        // firstly, Merge(a, b) = Merge(b, a) when the order of the merged string is preserve
        // the easiest thing is we try all possible case: a + b and b + a, but if we scale up the problem to n
        // in example, if n = 3, then the case are 3! = 6
        // if it is integer, then we could do it by plus two value
        // hot merge mot =
        int dif = 0;
        for (int loop = 0; loop < source.Length; loop++)
        {
            if (source[loop] != to[loop]) dif++;
        }

        return dif == 1;
    }

    public int LadderLength(string beginWord, string endWord, IList<string> wordList)
    {
        int rs = 0;
        HashSet<string> set = new HashSet<string>();
        for (int loop = 0; loop < wordList.Count; loop++)
        {
            set.Add(wordList[loop]);
        }
        if (!set.Contains(endWord)) return rs;
        HashSet<string> visited = new HashSet<string>();
        Dictionary<int, int> cache = new Dictionary<int, int>();
        
        Queue<string> queue = new Queue<string>();
        queue.Enqueue(beginWord);

        while (queue.Count > 0)
        {
            rs++;
            int count = queue.Count;
            for (int loop = 0; loop < count; loop++)
            {
                string s = queue.Dequeue();
                
                if (CanTransform(s, endWord)) return rs + 1;
                List<string> ss = Gen2(s, set, visited);
                foreach (string g in ss)
                {
                    if (set.Contains(g)) queue.Enqueue(g);
                }
            }
        }

        return 0;
    }
}
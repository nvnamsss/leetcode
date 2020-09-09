/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/
using System;
using System.Collections;
using System.Collections.Generic;
public class Solution {
    List<string> rs;
    int limit;
    public void backtrack(string s, int open, int close)
    {
        if (s.Length == limit * 2)
        {
            rs.Add(s);
        }

        if (open < limit)
        {
            backtrack(s + "(", open + 1, close + 1);
        }

        if (open > close)
        {
            backtrack(s + ")", open, close + 1);
        }


    }

    public IList<string> GenerateParenthesis(int n) {
        rs = new List<string>();
        limit = n;

        backtrack("", 0, 0);

        return rs;
    }
}
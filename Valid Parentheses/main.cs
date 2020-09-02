// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
 

// Example 1:

// Input: s = "()"
// Output: true
// Example 2:

// Input: s = "()[]{}"
// Output: true
// Example 3:

// Input: s = "(]"
// Output: false
// Example 4:

// Input: s = "([)]"
// Output: false
// Example 5:

// Input: s = "{[]}"
// Output: true
 

// Constraints:

// 1 <= s.length <= 104
// s consists of parentheses only '()[]{}'.

public class Solution {
    Stack<char> stack;
    private void work(char c){
        
    }

    public bool IsValid(string s) {
        stack = new Stack<char>();
        HashSet<char> open = new Hashset<char>();
        HashSet<char> close = new HashSet<char>();
        open.Add("(");
        open.Add("[");
        open.Add("{");

        close.Add(")");
        close.Add("]");
        close.Add("}");

        for (int loop = 0; loop < s.Length; loop++)
        {
            if (open.Contains(s[loop]))
            {

            }
            else
            {

            }
        }
    }
}
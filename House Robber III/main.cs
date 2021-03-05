/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:

Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

Output: 7 
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:

Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1


Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
*/


public class Solution {
    
    public int Rob(TreeNode root) {
        /*
        - flatten binary tree to array following this
        right root left then the above tree will become
        - recursive find with multi dp (each node in the right)
        the problem is no longer 1 dimension, it is multi dimension due to a house may connected by more than two house,
        I will call that problem is nth connection dimension, we must solve it without any confliction        
        */
    }
}
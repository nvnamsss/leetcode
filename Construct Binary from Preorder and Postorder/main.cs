/*
Return any binary tree that matches the given preorder and postorder traversals.

Values in the traversals pre and post are distinct positive integers.

 

Example 1:

Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]
 

Note:

1 <= pre.length == post.length <= 30
pre[] and post[] are both permutations of 1, 2, ..., pre.length.
It is guaranteed an answer exists. If there exists multiple answers, you can return any of them.
*/

public class Solution {
    int[] pre, post;
    public TreeNode make(int i0, int i1, int n)
    {
        if (n == 0) return null;
        TreeNode root = new TreeNode(pre[i0]);
        if (n == 1) return root;
        int l = 1;
        for (; l < n; ++l)
        {
            if (pre[i0 + 1] == post[i1 + l - 1]) break;
        }

        root.left = make(i0 + 1, i1, l);
        root.right = make(i0 + l + 1, i1 + l, n - 1 -l);
        return root;
    }

    public TreeNode ConstructFromPrePost(int[] pre, int[] post) {
        this.pre = pre;
        this.post = post;
        return make(0, 0, pre.Length);
    }

}
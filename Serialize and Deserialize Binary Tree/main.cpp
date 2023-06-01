/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

 

Example 1:


Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
Example 4:

Input: root = [1,2]
Output: [1,2]
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-1000 <= Node.val <= 1000
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
    string getObjectString(string data, int &i) {
        if (data[i] != '{') {
            return "";
        }

        int open = 0;
        string ans = "";
        do {
            ans += data[i];
            if (data[i] == '{') {
                open++;
            } else if (data[i] == '}') {
                open--;    
            }
            i++;
        }while(open>0);

        return ans;
    }

    string getNumericString(string data, int&i) {
        string ans = "";
        while (data[i] >= '0' && data[i] <= '9') {
            ans += data[i];
            i++;
        }

        return ans;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "null";
        }

        string ans = "{";
        ans += "\"val\": " + to_string(root->val) + ",";
        ans += "\"left\": " + serialize(root->left) + ",";
        ans += "\"right\": " + serialize(root->right);
        ans += "}";
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "" || data == "null") {
            return NULL;
        }
        TreeNode* ans = new TreeNode(0);
        int i = 0;
        while (i < data.size()) {
            if (data[i] == '"') {
                string key = "";
                while (data[i] == '"') {
                    key += data[i];
                    i++;
                }

                // next is ':' but we skip it
                i++;
                if (data[i] == '{') {
                    // value is object  
                    string value = getObjectString(data, i);
                    if (key == "left") {
                        ans->left = deserialize(value);
                    } else {
                        ans->right = deserialize(value);
                    }
                } else if (data[i] >= '0' && data[i] <= '9'){
                    // value is numeric
                    string value = getNumericString(data, i);
                    ans->val = stoi(value);
                } else {
                    // value is null
                    i += 3;
                }
            }
            i++;
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main() {
    Codec c;
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);

    TreeNode* n1 = new TreeNode(1);
    n1->left = n2;
    n1->right = n3;
    string d =  c.serialize(n1);
    TreeNode* t = c.deserialize(d);
    cout << t->val << endl;
}
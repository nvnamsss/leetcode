class Solution {
private:
    // Trie node structure
    struct TrieNode {
        bool isEndOfWord;
        unordered_map<char, TrieNode*> children;
        
        TrieNode() : isEndOfWord(false) {}
    };
    
    // Function to insert a word into the Trie
    void insertWord(TrieNode* root, const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->isEndOfWord = true;
    }
    
    bool recursive(string& s, TrieNode* root, vector<int>& dp, int start) {
        if (start == s.size()) {
            return true;
        }
        
        if (dp[start] != -1) {
            return dp[start] == 1;
        }
        
        TrieNode* curr = root;
        bool ans = false;
        
        for (int i = start; i < s.size(); i++) {
            char c = s[i];
            
            // If current character is not in Trie, break
            if (curr->children.find(c) == curr->children.end()) {
                break;
            }
            
            curr = curr->children[c];
            
            // If we found a complete word, try to segment the remainder
            if (curr->isEndOfWord) {
                ans = recursive(s, root, dp, i + 1);
                if (ans) {
                    break;
                }
            }
        }
        
        dp[start] = ans ? 1 : 0;
        return ans;
    }
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // Create frequency maps for character verification
        unordered_map<char, int> dictFreq;
        unordered_map<char, int> strFreq;
        
        // Count character frequencies in wordDict
        for (const string& word : wordDict) {
            for (char c : word) {
                dictFreq[c]++;
            }
        }
        
        // Count character frequencies in s
        for (char c : s) {
            strFreq[c]++;
        }
        
        // Check if s cannot be formed due to missing or insufficient characters
        for (auto& pair : strFreq) {
            char c = pair.first;
            int count = pair.second;
            
            if (dictFreq.find(c) == dictFreq.end()) {
                return false;
            }
        }
        
        // Build the Trie with words from wordDict
        TrieNode* root = new TrieNode();
        for (const string& word : wordDict) {
            insertWord(root, word);
        }
        
        // Initialize DP array for memoization (-1: not calculated, 0: false, 1: true)
        vector<int> dp(s.size(), -1);
        
        return recursive(s, root, dp, 0);
    }
};
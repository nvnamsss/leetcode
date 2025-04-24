#include <bits/stdc++.h>
using namespace std;


// Original O(n²) approach with bit manipulation
class Solution {
    unordered_map<char, int> vowels = {
        {'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}
    };

    bool checkValidSubarray(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < 5; ++i) {
            if (b[i] - a[i] == 0) {
                return false;
            }
        }
        return true;
    }

    bool checkValidArray(vector<int>& a) { 
        for (int i = 0; i < 5; ++i) {
            if (a[i] == 0) {
                return false;
            }
        }
        return true;
    }

    int binarySearch(vector<vector<int>>& arr, int l, int r) {
        while (l < r) {
            int m = l + (r - l) / 2;
            // calculate diff
            bool valid = checkValidSubarray(arr[l], arr[m]);
            if (valid) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return l;
    }

public:
    long long countOfSubstrings(string word, int k) {
        int n = word.length();
        long long result = 0;
        
        queue<int> consonants;
        vector<vector<int>> vowels_count(n + 1, vector<int>(5, 0));
        int l = 0;
        int r = 0;
        int c = 0;

        for (int i = 0; i < n; ++i) {
            vowels_count[i+1] = vowels_count[i];
            if (vowels.count(word[i])) {
                int index = vowels[word[i]];
                vowels_count[i][index]++;
            } else {
                consonants.push(i);
                if (consonants.size() == k) {
                    l = consonants.front();
                    consonants.pop();
                }
            }
            
            // calculate the possibilities by binary search
            if (checkValidSubarray(vowels_count[l], vowels_count[i + 1])) {
                int n_l = binarySearch(vowels_count, l, i + 1);
                result += n_l - l;
            }

            // int n_l = binarySearch(vowels_count, l, i + 1);
            // result += n_l - l;

        }

        return result;
    }
};

// Optimized sliding window approach O(n)
class OptimizedSolution {
public:
    long long countSubstrings(string word, int k) {
        int n = word.size();
        long long result = 0;
        
        // For each end position
        for (int right = 0; right < n; right++) {
            vector<int> vowelCounts(5, 0); // Count of each vowel
            int uniqueVowels = 0;          // Number of unique vowels in current window
            int consonantCount = 0;        // Count of consonants
            
            // Go backwards from right to find all valid windows
            for (int left = right; left >= 0; left--) {
                char c = word[left];
                
                if (isVowel(c)) {
                    int idx = getVowelIndex(c);
                    if (vowelCounts[idx] == 0) {
                        uniqueVowels++;
                    }
                    vowelCounts[idx]++;
                } else {
                    consonantCount++;
                }
                
                // If we exceed k consonants, no earlier starting position will work
                if (consonantCount > k) {
                    break;
                }
                
                // If we have all vowels and exactly k consonants, we found a valid substring
                if (uniqueVowels == 5 && consonantCount == k) {
                    result++;
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol1;
    OptimizedSolution sol2;
    FrequencyBasedSolution sol3;
    
    vector<pair<string, int>> testCases = {
        {"aeioqq", 1},          // Expected: 0
        {"aeiou", 0},           // Expected: 1
        {"ieaouqqieaouqq", 1}   // Expected: 3
    };
    
    for (auto& tc : testCases) {
        cout << "Original: " << sol1.countSubstrings(tc.first, tc.second);
        cout << ", Optimized: " << sol2.countSubstrings(tc.first, tc.second);
        cout << ", Frequency-based: " << sol3.countSubstrings(tc.first, tc.second) << endl;
    }
    
    return 0;
}


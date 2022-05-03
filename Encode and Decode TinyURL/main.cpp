/*
Note: This is a companion problem to the System Design problem: Design TinyURL.
TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk. Design a class to encode a URL and decode a tiny URL.

There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.

Implement the Solution class:

Solution() Initializes the object of the system.
String encode(String longUrl) Returns a tiny URL for the given longUrl.
String decode(String shortUrl) Returns the original long URL for the given shortUrl. It is guaranteed that the given shortUrl was encoded by the same object.
 

Example 1:

Input: url = "https://leetcode.com/problems/design-tinyurl"
Output: "https://leetcode.com/problems/design-tinyurl"

Explanation:
Solution obj = new Solution();
string tiny = obj.encode(url); // returns the encoded tiny url.
string ans = obj.decode(tiny); // returns the original url after deconding it.
 

Constraints:

1 <= url.length <= 104
url is guranteed to be a valid URL.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    string alphabet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string prefix = "https://tinyurl.com/";
    unordered_map<string, string> m;
    int counter = 0;

    string get_random() {
        string s = "";
        for (int i = 0; i < 6; i++)
        {
            s += alphabet[rand() % 62];
        }
        
        return s;
    }

public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string k = get_random();
        m[k] = longUrl;
        return prefix + k; 
    }

    // Decodes a shortened URL to its orig  inal URL.
    string decode(string shortUrl) {
        string s(shortUrl.begin(), shortUrl.end());
        int sublength = prefix.size();
        s = s.substr(sublength);
        return m[s];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main() {
    Solution s;
    string encoded = s.encode("himom");
    cout << encoded << endl;
    cout << s.decode(encoded) << endl;

    encoded = s.encode("toowastemoney");
    cout << encoded << endl;
    cout << s.decode(encoded) << endl;

    encoded = s.encode("toowastemoney2");
    cout << encoded << endl;
    cout << s.decode(encoded) << endl;
}
/*
Alice is texting Bob using her phone. The mapping of digits to letters is shown in the figure below.


In order to add a letter, Alice has to press the key of the corresponding digit i times, where i is the position of the letter in the key.

For example, to add the letter 's', Alice has to press '7' four times. Similarly, to add the letter 'k', Alice has to press '5' twice.
Note that the digits '0' and '1' do not map to any letters, so Alice does not use them.
However, due to an error in transmission, Bob did not receive Alice's text message but received a string of pressed keys instead.

For example, when Alice sent the message "bob", Bob received the string "2266622".
Given a string pressedKeys representing the string received by Bob, return the total number of possible text messages Alice could have sent.

Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: pressedKeys = "22233"
Output: 8
Explanation:
The possible text messages Alice could have sent are:
"aaadd", "abdd", "badd", "cdd", "aaae", "abe", "bae", and "ce".
Since there are 8 possible messages, we return 8.
Example 2:

Input: pressedKeys = "222222222222222222222222222222222222"
Output: 82876089
Explanation:
There are 2082876103 possible text messages Alice could have sent.
Since we need to return the answer modulo 109 + 7, we return 2082876103 % (109 + 7) = 82876089.
 

Constraints:

1 <= pressedKeys.length <= 105
pressedKeys only consists of digits from '2' - '9'.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int mod = 1e9 + 7;
    void countk(vector<int>& dp, int n, int k) {
        for (int i = k; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                dp[i] = (dp[i] + dp[i-j]) % mod;
            }
        }
    }
    
public:
    int countTexts(string pressedKeys) {
        vector<vector<int>> pressed;
        char lastPress = 'a';
        vector<int> dp3 = vector<int>(pressedKeys.size() + 3, 0);
        vector<int> dp4 = vector<int>(pressedKeys.size() + 4, 0);

        dp3[0] = 1;
        dp3[1] = 1;
        dp3[2] = 2;
        dp4[0] = 1;
        dp4[1] = 1;
        dp4[2] = 2;
        dp4[3] = 4;

        countk(dp3, pressedKeys.size(), 3);
        countk(dp4, pressedKeys.size(), 4);
        for (int i = 0; i < pressedKeys.size(); i++)
        {
            if (lastPress != pressedKeys[i]) {
                pressed.push_back({0, pressedKeys[i] - '0'});
                lastPress = pressedKeys[i];
            }

            pressed[pressed.size() - 1][0]++;
        }
        
        long ans = 1;
        for (int i = 0; i < pressed.size(); i++)
        {
            int times = pressed[i][0];
            int digit = pressed[i][1];

            if (digit == 7 || digit == 9) {
                times = dp4[times];
            } else {
                times = dp3[times];
            }
        
            ans = (ans * times) % mod;
        }

        return ans;
    }
};

int main() {
    Solution s;
    cout << s.countTexts("777") << endl;
    cout << s.countTexts("777777777") << endl;
    cout << s.countTexts("7777777777777777777777777777777777777777777") << endl;
    cout << s.countTexts("222222222222222222222222222222222222") << endl;
}
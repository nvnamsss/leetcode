/*
A teacher is writing a test with n true/false questions, with 'T' denoting true and 'F' denoting false. He wants to confuse the students by maximizing the number of consecutive questions with the same answer (multiple trues or multiple falses in a row).

You are given a string answerKey, where answerKey[i] is the original answer to the ith question. In addition, you are given an integer k, the maximum number of times you may perform the following operation:

Change the answer key for any question to 'T' or 'F' (i.e., set answerKey[i] to 'T' or 'F').
Return the maximum number of consecutive 'T's or 'F's in the answer key after performing the operation at most k times.



Example 1:

Input: answerKey = "TTFF", k = 2
Output: 4
Explanation: We can replace both the 'F's with 'T's to make answerKey = "TTTT".
There are four consecutive 'T's.
Example 2:

Input: answerKey = "TFFT", k = 1
Output: 3
Explanation: We can replace the first 'T' with an 'F' to make answerKey = "FFFT".
Alternatively, we can replace the second 'T' with an 'F' to make answerKey = "TFFF".
In both cases, there are three consecutive 'F's.
Example 3:

Input: answerKey = "TTFTTFTT", k = 1
Output: 5
Explanation: We can replace the first 'F' to make answerKey = "TTTTTFTT"
Alternatively, we can replace the second 'F' to make answerKey = "TTFTTTTT".
In both cases, there are five consecutive 'T's.


Constraints:

n == answerKey.length
1 <= n <= 5 * 104
answerKey[i] is either 'T' or 'F'
1 <= k <= n
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int slidingWindow(string answerKey, int k, char target)
    {
        int left = 0;
        int right = 0;
        int ans = 0;
        while (right < answerKey.size())
        {

            if (answerKey[right] != target)
            {
                if (k == 0)
                {
                    while (answerKey[left] == target)
                    {
                        left++;
                    }
                    left++;
                    k++;
                }
                k--;
            }
            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }

public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        int t = slidingWindow(answerKey, k, 'T');
        int f = slidingWindow(answerKey, k, 'F');
        return max(t, f);
    }
};

int main() {
    Solution s;
    string answerKey = "TTFF";
    cout << s.maxConsecutiveAnswers(answerKey, 2) << endl;

    answerKey = "TTFTTFTT";
    cout << s.maxConsecutiveAnswers(answerKey, 1) << endl;
}
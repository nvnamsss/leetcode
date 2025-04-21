#include <bits/stdc++.h>
using namespace std;


class Problem {
    public:
    int findMaxSubarray(vector<int>& arr) {
        vector<int> prefix_sum = vector<int>(arr.size() + 1);
        int ans = INT32_MIN;
        // start of the subarray
        int position = 0;
        // length of subarray
        int length = 0;

        for (int i= 0; i< arr.size(); ++i) {
            prefix_sum[i + 1] = prefix_sum[i] + arr[i];
        }

        for (int i = 0; i< arr.size(); ++i) {
            for (int j = 1; j < arr.size() - i; ++j) {
                int sum = prefix_sum[i + j] - prefix_sum[i];
                if (sum > ans) {
                    ans = sum;
                    position = i;
                    length = j;
                }
            }
        }

        return ans;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, -7, 10};
    Problem p;
    int ans = p.findMaxSubarray(arr);
    cout << ans;
}
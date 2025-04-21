class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            int n = differences.size();
            vector<long> prefix = vector<long>(n + 1);
            long minDiff = INT32_MAX;
            long maxDiff = INT32_MIN;
            for (int i = 0; i < differences.size(); ++i) {
                prefix[i+1] = prefix[i] + differences[i];
                minDiff = min(minDiff, prefix[i+1]);
                maxDiff = max(maxDiff, prefix[i+1]);
            }
    
            long start = lower;
            long end = upper;
            if (minDiff < 0) {
                start -= minDiff;
            }
    
            if (maxDiff > 0) {
                end -= maxDiff;
            }
    
            long ans = end - start + 1;
    
            // cout << start << " " << endl;
            if (ans < 0) {
                return 0;
            }
    
            return ans;
        }
    };
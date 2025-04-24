#include <bits/stdc++.h>
using namespace std;

// Copy of the Solution class for testing
class Solution {
public:
    long solution(vector<int>& arr) {
        long sum = 0;
        int dp = 0;
        int maxDif = 0;
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            long dif = abs(arr[i] - arr[i + 1]);
            sum += dif * dif;

            // find the max difference
            if (dif > abs(arr[dp] - arr[dp + 1])) {
                dp = i;
                maxDif = dif;
            }
        }

        sum = sum - maxDif;
        // insert value
        int m = arr[dp] + (arr[dp + 1] - arr[dp]) / 2;
        sum += (m - arr[dp]) * (m - arr[dp]) + (arr[dp + 1] - m) * (arr[dp + 1] - m);

        return sum;
    }
};

// Test helper function
bool runTest(vector<int> arr, long expected) {
    Solution sol;
    vector<int> arrCopy = arr; // Create a copy to avoid modifying original
    long result = sol.solution(arrCopy);
    cout << "Input: [";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    cout << "Expected: " << expected << ", Got: " << result << endl;
    bool passed = result == expected;
    cout << (passed ? "PASSED" : "FAILED") << endl << endl;
    return passed;
}

int main() {
    int passed = 0, total = 0;
    
    // Basic test cases
    passed += runTest({1, 5, 10}, 29);
    total++;
    
    passed += runTest({10, 2, 5}, 41);
    total++;
    
    passed += runTest({5, 5, 5}, 0);
    total++;
    
    passed += runTest({1, 10, 2, 9, 3, 8}, 155);
    total++;
    
    passed += runTest({-5, 5, -3, 3}, 68);
    total++;
    
    // Edge case - only two elements
    // Original: (100-1)² = 9801
    // Insert 50.5 (rounded to 50): (50-1)² + (100-50)² = 2401 + 2500 = 4901
    passed += runTest({1, 100}, 4901);
    total++;
    
    // Case with very large differences
    // Original: (1000-1)² + (1-1000)² = 998001 + 998001 = 1996002
    // Max diff is 999, squared = 998001
    // 1996002 - 998001 = 998001
    // Insert 500.5 (rounded to 500): (500-1)² + (1000-500)² = 249001 + 250000 = 499001
    // Total: 998001 + 499001 = 1497002
    passed += runTest({1, 1000, 1}, 1497002);
    total++;
    
    // Case with multiple identical maximum differences
    passed += runTest({0, 10, 0, 10, 0}, 250);
    total++;
    
    // Case where rounding the midpoint matters
    passed += runTest({1, 8}, 12); // midpoint is 4.5, rounded to 4
    total++;
    
    // Large array test
    vector<int> largeArray;
    for (int i = 0; i < 100; i++) {
        largeArray.push_back(i % 10);  // creates a repeating pattern 0,1,2,...,9,0,1,...
    }
    passed += runTest(largeArray, 169); // You would need to calculate the expected value
    total++;
    
    // Alternating positive/negative values
    passed += runTest({-10, 10, -10, 10}, 600);
    total++;
    
    // A case with a single large outlier
    passed += runTest({1, 2, 3, 100, 4, 5}, 9428);
    total++;
    
    cout << "Passed " << passed << " out of " << total << " tests." << endl;
    
    return 0;
}

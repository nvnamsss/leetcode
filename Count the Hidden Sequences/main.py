from typing import List
import sys

class Solution:
    def numberOfArrays(self, differences: List[int], lower: int, upper: int) -> int:
        prefix = [0] * (len(differences) + 1)
        
        min_diff = -sys.maxsize - 1
        max_diff = sys.maxsize
        
        for i in range(len(differences)):
            prefix[i + 1] = prefix[i] + differences[i]
            min_diff = min(min_diff, prefix[i + 1])
            max_diff = max(max_diff, prefix[i + 1])

        start = lower
        end = upper
        if min_diff < 0:
            start -= min_diff
        
        if max_diff > 0:
            end -= max_diff

        return max(0, end - start + 1)


def main():
    solution = Solution()
    
    # Test cases
    test_cases = [
        {
            'differences': [1, -3, 4],
            'lower': 1,
            'upper': 6,
            'expected': 2
        },
        {
            'differences': [3, -4, 5, 1, -2],
            'lower': -4,
            'upper': 5,
            'expected': 4
        },
        {
            'differences': [4, -7, 2],
            'lower': 3,
            'upper': 6,
            'expected': 0
        }
    ]
    
    for i, test in enumerate(test_cases, 1):
        result = solution.numberOfArrays(test['differences'], test['lower'], test['upper'])
        print(f"Test case {i}:")
        print(f"Input: differences = {test['differences']}, lower = {test['lower']}, upper = {test['upper']}")
        print(f"Expected: {test['expected']}")
        print(f"Output: {result}")
        print(f"Pass: {result == test['expected']}\n")

if __name__ == "__main__":
    main()


class Solution:
    def calDigit(self, n: int) -> int:
        sum = 0
        while n > 0:
            v = n % 10
            n = (n - v) / 10
            sum += v

        return sum
    
    def countLargestGroup(self, n: int) -> int:
        m = {}
        max_size = 0
        for i in range(1, n + 1):
            sum = self.calDigit(i)
            if sum in m:
                m[sum] += 1
            else:
                m[sum] = 1
            max_size = max(max_size, m[sum])

        ans = 0
        for k, v in m.items():
            if v == max_size:
                ans += 1
        return ans

def main():
    solution = Solution()
    
    # Test cases
    test_cases = [4, 13, 2, 15, 24]
    expected_outputs = [2, 4, 2, 6, 5]
    
    for i, n in enumerate(test_cases):
        result = solution.countLargestGroup(n)
        print(f"Input: n = {n}")
        print(f"Output: {result}")
        print(f"Expected: {expected_outputs[i]}")
        print(f"Test case {'passed' if result == expected_outputs[i] else 'failed'}")
        print("-" * 30)

if __name__ == "__main__":
    main()
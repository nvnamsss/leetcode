from typing import List


class Solution:
    def count(self, n: str) -> List[List[int]]:
        freqs : List[List[int]] = []

        i = 0
        while i < len(n):
            j = i
            while j < len(n) and n[j] == n[i]:
                j += 1
            # freq - value
            freqs.append([j - i, int(n[i])])
            i = j
            
        return freqs

    def say(self, c: List[List[int]]) -> str:
        s = ""
        for freq in c:
            s += str(freq[0]) + str(freq[1])
        return s

    def countAndSay(self, n: int) -> str:
        ans = "1"
        for i in range(1, n):
            freqs = self.count(ans)
            ans = self.say(freqs)

        return ans
    
if __name__ == "__main__":
    n = 4
    s = Solution()
    print(s.countAndSay(n))  # Output: "1211"
from typing import List


class Solution:
    def recursive(self, matchsticks, mask, side_formed):
        if side_formed == 3:
            return True
        
        return False
    
    def makesquare(self, matchsticks: List[int]) -> bool:
        max = sum(matchsticks)
        l = len(matchsticks)
        if max % 4 != 0:
            return False
        
        return self.recursive(matchsticks, (1 << l), 0)
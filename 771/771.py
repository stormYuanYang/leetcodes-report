#MIT License
#Copyright (c) 2018 yangyuan
import sys

class Solution:
    def numJewelsInStones(self, J, S):
        """
        :type J: str
        :type S: str
        :rtype: int
        """
        jewelTypes = {}
        for jewel in J:
            jewelTypes[jewel] = None
        jewelNum = 0
        for stone in S:
            if stone in jewelTypes:
                jewelNum += 1
        return jewelNum
J = "aA"
S = "aAAbbbb"
solution = Solution()
print(solution.numJewelsInStones(J, S))

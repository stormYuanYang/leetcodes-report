#MIT License
#Copyright (c) 2018 yangyuan
class Solution:
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        h, v = 0, 0
        for c in moves:
            if c == 'R':
                h += 1
            elif c == 'L':
                h -= 1
            elif c == 'U':
                v += 1
            else:
                v -= 1
        if h == 0 and v == 0:
            return True
        else:
            return False

slt = Solution()
moves = "UD"
print(slt.judgeCircle(moves))

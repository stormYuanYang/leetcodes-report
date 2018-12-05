#MIT Licene
#Copyright (c) 2018 yangyuan
import sys

class RecentCounter:
    def __init__(self):
        self.m_array         = [0] * 10001
        self.m_index         = 1
        self.m_lowBoundIndex = 1

    def ping(self, t):
        """
        :type t: int
        :rtype: int
        """
        self.m_array[self.m_index] = t
        self.m_index += 1

        lowBound = t - 3000
        first    = self.m_lowBoundIndex
        last     = self.m_index - 1
        mid      = None
        while first <= last:
            mid = first + ((last - first) >> 1)
            if lowBound <= self.m_array[mid] and lowBound > self.m_array[mid - 1]:
                break
            if lowBound < self.m_array[mid]:
                last = mid - 1
            else:
                first = mid + 1
        self.m_lowBoundIndex = mid
        return (self.m_index - self.m_lowBoundIndex)

# Your RecentCounter object will be instantiated and called as such:
obj = RecentCounter()
for lineStr in sys.stdin:
    numbers = map(int, lineStr.split())
    for number in numbers:
        param_1 = obj.ping(number)
        print(param_1)

# Last updated: 17/08/2026, 16:57:31
1class Solution(object):
2    def singleNumber(self, nums):
3        """
4        :type nums: List[int]
5        :rtype: int
6        """
7        result = 0
8
9        for num in nums:
10            result ^= num
11
12        return result
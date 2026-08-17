# Last updated: 17/08/2026, 16:35:37
1class Solution(object):
2    def missingNumber(self, nums):
3        """
4        :type nums: List[int]
5        :rtype: int
6        """
7        for i in range(len(nums)+1):
8            if i not in nums:
9                return i
10                       
# Last updated: 17/08/2026, 16:36:04
1class Solution(object):
2    def missingNumber(self, nums):
3        """
4        :type nums: List[int]
5        :rtype: int
6        """
7        new = set(nums)
8        for i in range(len(new)+1):
9            if i not in nums:
10                return i
11                       
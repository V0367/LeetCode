# Last updated: 17/08/2026, 16:54:53
1class Solution(object):
2    def singleNumber(self, nums):
3        """
4        :type nums: List[int]
5        :rtype: int
6        """
7        n = len(nums)
8
9        if n==1:
10            return nums[0]
11
12        result = reduce(xor,nums)
13
14        return result
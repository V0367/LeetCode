# Last updated: 17/08/2026, 16:30:14
1class Solution(object):
2    def missingNumber(self, nums):
3        """
4        :type nums: List[int]
5        :rtype: int
6        """
7        for i in nums:
8            if i-1>=0 and i-1 not in nums: 
9                return i-1
10                
11            elif i+1<=len(nums) and i+1 not in nums:
12                return i+1
13                       
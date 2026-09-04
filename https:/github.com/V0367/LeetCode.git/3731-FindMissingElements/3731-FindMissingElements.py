# Last updated: 04/09/2026, 17:12:04
1class Solution(object):
2    def findMissingElements(self, nums):
3        
4        missing = []
5        nums = sorted(nums)
6        n = len(nums)
7
8        for i in range(nums[0],nums[n-1]):
9            if i not in set(nums):
10                missing.append(i)
11        return missing 
12        
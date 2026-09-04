# Last updated: 04/09/2026, 17:13:43
1class Solution(object):
2    def findMissingElements(self, nums):
3        
4        missing = []
5        num_set = set(nums)
6
7        for i in range(min(nums),max(nums)):
8            if i not in num_set:
9                missing.append(i)
10        return missing 
11        
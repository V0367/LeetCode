# Last updated: 04/09/2026, 17:12:37
1class Solution(object):
2    def findMissingElements(self, nums):
3        
4        missing = []
5        nums = sorted(nums)
6        num_set = set(nums)
7        n = len(nums)
8
9        for i in range(nums[0],nums[n-1]):
10            if i not in num_set:
11                missing.append(i)
12        return missing 
13        
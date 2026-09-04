# Last updated: 04/09/2026, 17:06:06
1class Solution(object):
2    def findMissingElements(self, nums):
3        
4        missing = []
5        l = min(nums)
6        u = max(nums)
7
8
9        for i in range(l+1,u):
10            nums = sorted(nums)
11            if i not in nums:
12                missing.append(i)
13        return missing 
14        
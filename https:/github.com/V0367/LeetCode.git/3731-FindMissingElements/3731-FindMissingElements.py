# Last updated: 04/09/2026, 17:09:14
1class Solution(object):
2    def findMissingElements(self, nums):
3        
4        missing = []
5        l = min(nums)
6        u = max(nums)
7        nums = sorted(nums)
8
9
10        for i in range(l+1,u):
11            
12            if i not in nums:
13                missing.append(i)
14        return missing 
15        
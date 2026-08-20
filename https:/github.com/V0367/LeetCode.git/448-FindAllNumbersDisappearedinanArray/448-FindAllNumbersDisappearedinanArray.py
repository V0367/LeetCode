# Last updated: 20/08/2026, 11:13:24
1class Solution(object):
2    def findDisappearedNumbers(self, nums):
3        n = len(nums)
4        missing = []
5        for x in nums:
6            index = abs(x) - 1
7            nums[index] = -abs(nums[index])
8        
9        for i in range(n):
10            if nums[i]>0:
11                missing.append(i+1)
12        return missing
13                
14        
15        
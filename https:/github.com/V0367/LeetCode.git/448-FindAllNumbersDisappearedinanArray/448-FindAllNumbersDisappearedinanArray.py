# Last updated: 20/08/2026, 11:12:49
1class Solution(object):
2    def findDisappearedNumbers(self, nums):
3        n = len(nums)
4        missing = []
5        for x in nums:
6            index = abs(x) - 1
7            if nums[index]>0:
8                nums[index] = -nums[index]
9        
10        for i in range(n):
11            if nums[i]>0:
12                missing.append(i+1)
13        return missing
14                
15        
16        
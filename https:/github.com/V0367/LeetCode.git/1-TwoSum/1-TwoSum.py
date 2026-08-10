# Last updated: 10/08/2026, 12:12:32
1class Solution(object):
2    def twoSum(self, nums, target):
3        for i in range(len(nums)):
4            for j in range(i+1,len(nums)):
5                if nums[i]+nums[j]==target:
6                    return (i,j)
7                
8        
# Last updated: 05/09/2026, 20:25:08
1class Solution(object):
2    def missingInteger(self, nums):
3        sum1 = nums[0]
4
5        for i in range(len(nums)-1):
6            if nums[i+1] == nums[i] + 1:
7                sum1 += nums[i+1]
8            else:
9                break
10            
11        while True:
12            if sum1 not in nums:
13                return sum1
14            else:
15                sum1 += 1
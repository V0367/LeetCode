# Last updated: 14/08/2026, 14:52:39
1class Solution(object):
2    def maxSubArray(self, nums):
3        current_sum = nums[0]
4        max_sum = max(nums)
5
6        for i in range(1,len(nums)):
7            if current_sum+nums[i]<=nums[i]:
8                current_sum = nums[i]
9            else:
10                current_sum+=nums[i]
11
12            if max_sum<current_sum:
13                max_sum=current_sum
14        return max_sum
15
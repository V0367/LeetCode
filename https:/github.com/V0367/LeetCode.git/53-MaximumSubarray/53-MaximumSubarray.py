# Last updated: 14/08/2026, 15:10:34
1class Solution(object):
2    def maxSubArray(self, nums):
3        current_sum = nums[0]
4        max_sum = nums[0]
5
6        for i in range(1,len(nums)):
7            current_sum = max(nums[i], current_sum+nums[i])
8            max_sum = max(max_sum, current_sum)
9        return max_sum
10
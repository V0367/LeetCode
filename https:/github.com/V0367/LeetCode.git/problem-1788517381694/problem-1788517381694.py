# Last updated: 04/09/2026, 15:53:01
1class Solution(object):
2    def lengthOfLIS(self, nums):
3        """
4        :type nums: List[int]
5        :rtype: int
6        """
7        n = len(nums)
8
9        dp = [1]*n
10
11        for i in range(n):
12            for j in range(i):
13                if nums[j] < nums[i]:
14                    dp[i] = max(dp[i], dp[j]+1)
15        return max(dp)
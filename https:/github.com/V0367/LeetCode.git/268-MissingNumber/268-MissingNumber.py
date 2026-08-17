# Last updated: 17/08/2026, 16:38:54
1class Solution(object):
2    def missingNumber(self, nums):
3        """
4        :type nums: List[int]
5        :rtype: int
6        """
7        n = len(nums)
8        sum1 = (n*(n+1))/2
9        actual = sum(nums)
10        return sum1 - actual 
11                       
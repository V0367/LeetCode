# Last updated: 14/08/2026, 15:23:08
1from collections import Counter
2
3class Solution(object):
4    def majorityElement(self, nums):
5        n = len(nums)
6        counts = dict(Counter(nums))
7        for key, value in counts.items():
8            if value>n/2:
9                return key
10        
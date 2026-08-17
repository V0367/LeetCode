# Last updated: 17/08/2026, 11:06:21
1class Solution(object):
2    def longestConsecutive(self, nums):
3        c_count = 0
4        max_count = 0
5        new = set(nums)
6        n = len(new)
7        for x in new:
8            if x-1 not in new:
9                current = x
10                c_count = 1
11                while current + 1 in new:
12                    current +=1
13                    c_count+=1
14            max_count = max(max_count,c_count)
15        return max_count
16        
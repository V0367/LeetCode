# Last updated: 04/09/2026, 16:34:41
1class Solution(object):
2    def missingMultiple(self, nums, k):
3
4        nums_set = set(nums)
5
6        i = 1
7
8        while True:
9            multiple = k * i
10
11            if multiple not in nums:
12                return multiple
13
14            i += 1
15            
16      
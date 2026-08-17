# Last updated: 17/08/2026, 11:15:36
1class Solution(object):
2    def longestConsecutive(self, nums):
3        nums_set = set(nums)
4        longest = 0
5        for x in nums_set:
6            if x-1 not in nums_set:
7                current = x
8                length = 1
9                while current+1 in nums_set:
10                    current+=1
11                    length +=1
12                longest = max(longest,length)
13        return longest
14        
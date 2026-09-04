# Last updated: 04/09/2026, 11:26:11
1class Solution(object):
2    def firstStableIndex(self, nums, k):
3        n = len(nums)
4        suffix_min = [0]*n
5        suffix_min[n-1] = nums[n-1]
6
7        if n == 1:
8            return 0
9
10        for i in range(n-2,-1,-1):
11            suffix_min[i] = min(nums[i],suffix_min[i+1])
12        
13        prefix_max = 0
14
15        for i in range(n):
16            prefix_max = max(prefix_max, nums[i])
17
18            if prefix_max - suffix_min[i] <= k:
19                return i
20        
21        return -1
22
23        
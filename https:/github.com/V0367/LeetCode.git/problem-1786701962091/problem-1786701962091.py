# Last updated: 14/08/2026, 15:36:02
1from collections import Counter
2
3class Solution(object):
4    def majorityElement(self, nums):
5        candidate = nums[0]
6        score = 1
7        for i in range(1,len(nums)):
8            if candidate==nums[i]:
9                score +=1
10            else:
11                score -=1
12
13            if score < 0:
14                candidate = nums[i]
15                score = 0
16        return candidate
17        
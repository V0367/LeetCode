# Last updated: 14/08/2026, 15:44:28
1from collections import Counter
2
3class Solution(object):
4    def majorityElement(self, nums):
5        candidate = nums[0]
6        score = 0
7
8        for x in nums:
9            if score == 0:
10                candidate = x
11            
12            if candidate == x:
13                score+=1
14            else:
15                score-=1
16
17        return candidate
18        
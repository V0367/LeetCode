# Last updated: 20/08/2026, 10:50:02
1class Solution(object):
2    def findDisappearedNumbers(self, nums):
3        n = len(nums)
4        new = set(nums)
5        result = set()
6        for i in range(1,n+1):
7            if i not in new:
8                result.add(i)
9        r = list(result)
10        return r
11                
12        
13        
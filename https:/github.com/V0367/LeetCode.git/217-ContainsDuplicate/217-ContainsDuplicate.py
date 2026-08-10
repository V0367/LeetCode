# Last updated: 10/08/2026, 11:06:15
1class Solution(object):
2    def containsDuplicate(self, nums):
3        t = set()
4        for i in nums:
5            if i in t:
6                return True
7            t.add(i)
8        return False
9        
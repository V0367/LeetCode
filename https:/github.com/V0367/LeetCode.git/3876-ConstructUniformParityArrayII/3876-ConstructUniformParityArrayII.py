# Last updated: 04/09/2026, 14:48:10
1class Solution(object):
2    def uniformArray(self, nums1):
3        """
4        :type nums1: List[int]
5        :rtype: bool
6        """
7        mn = min(nums1)
8
9        if mn % 2 == 1:
10            return True
11
12        # mn is even.
13        # If there is any odd number, impossible.
14        for x in nums1:
15            if x % 2 == 1:
16                return False
17
18        return True
19
20
21
22        
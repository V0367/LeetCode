# Last updated: 17/08/2026, 17:00:39
1class Solution(object):
2    def intersection(self, nums1, nums2):
3        """
4        :type nums1: List[int]
5        :type nums2: List[int]
6        :rtype: List[int]
7        """
8        nums1 = set(nums1)
9        nums2 = set(nums2)
10        result = []
11
12        for x in nums1:
13            if x in nums2:
14                result.append(x)
15        return result
16                
17        
# Last updated: 17/08/2026, 17:12:26
1class Solution(object):
2    def intersect(self, nums1, nums2):
3        """
4        :type nums1: List[int]
5        :type nums2: List[int]
6        :rtype: List[int]
7        """
8        nums1 = sorted(nums1)
9        nums2 = sorted(nums2)
10        p1 = 0
11        p2 = 0
12        result = []
13        while p1<len(nums1) and p2<len(nums2):
14            if nums1[p1]==nums2[p2]:
15                result.append(nums1[p1])
16                p1+=1
17                p2+=1
18            elif nums1[p1]<nums2[p2]:
19                p1+=1
20            else:
21                p2+=1
22
23        return result
24
25        
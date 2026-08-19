# Last updated: 19/08/2026, 11:57:31
1class Solution(object):
2    def intersect(self, nums1, nums2):
3        nums1.sort()
4        nums2.sort()
5
6        p1 = 0
7        p2 = 0
8        result = []
9
10        while p1 < len(nums1) and p2 < len(nums2):
11            if nums1[p1] == nums2[p2]:
12                result.append(nums1[p1])
13                p1 += 1
14                p2 += 1
15
16            elif nums1[p1] < nums2[p2]:
17                p1 += 1
18
19            else:
20                p2 += 1
21
22        return result
# Last updated: 14/08/2026, 16:52:41
1class Solution(object):
2    def maxProduct(self, nums):
3        current_product = nums[0]
4        min_product = nums[0]
5        max_product = nums[0]
6
7        for i in range(1,len(nums)):
8            x = nums[i]
9
10            old_min = min_product
11            old_max = max_product
12
13            min_product = min(x, old_min*x, old_max*x)
14            max_product = max(x, old_min*x, old_max*x)
15
16            current_product = max(current_product, max_product)
17
18        return current_product
19
20        
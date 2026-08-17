# Last updated: 17/08/2026, 10:28:50
1class Solution(object):
2    def productExceptSelf(self, nums):
3        n = len(nums)
4        answer = [1]*n
5
6        left_product = 1
7
8        for i in range(n):
9            answer[i] = left_product
10            left_product *= nums[i]
11
12        right_product = 1
13
14        for i in range(n-1,-1,-1):
15            answer[i] *= right_product
16            right_product *= nums[i]
17        
18        return answer
19            
20        
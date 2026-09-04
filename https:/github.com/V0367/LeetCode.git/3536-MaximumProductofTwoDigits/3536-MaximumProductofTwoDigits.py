# Last updated: 04/09/2026, 16:53:44
1class Solution(object):
2    def maxProduct(self, n):
3        
4        nums = []
5
6        while n>0:
7            digit = n%10
8
9            nums.append(digit)
10
11            n//=10
12        
13        num1 = nums.pop(nums.index(max(nums)))
14        num2 = nums.pop(nums.index(max(nums)))
15
16        return num1 * num2
17
18
19        
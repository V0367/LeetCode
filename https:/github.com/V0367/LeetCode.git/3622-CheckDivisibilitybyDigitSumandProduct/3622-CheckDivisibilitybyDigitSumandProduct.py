# Last updated: 04/09/2026, 16:22:16
1class Solution(object):
2    def checkDivisibility(self, n):
3
4        original = n
5
6        digit_sum = 0
7        digit_product = 1
8
9        while n > 0:
10            digit  = n%10
11
12            digit_sum += digit
13            digit_product *= digit
14
15            n//=10
16
17        num = digit_sum + digit_product
18
19        return original % num == 0
20
21
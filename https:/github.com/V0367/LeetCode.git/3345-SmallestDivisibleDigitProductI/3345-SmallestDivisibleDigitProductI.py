# Last updated: 05/09/2026, 20:15:03
1class Solution(object):
2    def smallestNumber(self, n, t):
3        
4        while True:
5            num = n
6            product = 1
7
8            while num > 0:
9                digit = num % 10
10                product *= digit
11                num //= 10
12
13            if product % t == 0:
14                return n
15
16            n += 1
17    
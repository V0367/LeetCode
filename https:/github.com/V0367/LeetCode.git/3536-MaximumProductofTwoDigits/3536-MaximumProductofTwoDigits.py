# Last updated: 04/09/2026, 17:01:55
1class Solution(object):
2    def maxProduct(self, n):
3        
4        largest = 0
5        second = 0
6
7
8        while n>0:
9            digit = n%10
10            n//=10
11
12            if digit >= largest:
13                second = largest
14                largest = digit
15            elif digit > second:
16                second = digit
17
18        return largest * second
19
20
21        
# Last updated: 10/08/2026, 11:58:39
1class Solution(object):
2    def isAnagram(self, s, t):
3        if (len(s)!=len(t)):
4            return False
5        
6        count = {}
7
8        for i in s:
9            count[i] = count.get(i, 0) + 1
10        
11        for i in t:
12            count[i] = count.get(i, 0) - 1
13        
14        for j in count:
15            if count.get(j) != 0:
16                return False
17        return True
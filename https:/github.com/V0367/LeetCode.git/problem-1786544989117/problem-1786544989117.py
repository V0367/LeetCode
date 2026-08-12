# Last updated: 12/08/2026, 19:59:49
1class Solution(object):
2    def isPalindrome(self, s):
3        t = s.lower()
4        cleaned = "".join(char for char in t if char.isalnum())
5        n = len(cleaned)
6        if cleaned == " " or cleaned==cleaned[::-1]:
7            return True
8        else:
9            return False
10        """
11        :type s: str
12        :rtype: bool
13        """
14        
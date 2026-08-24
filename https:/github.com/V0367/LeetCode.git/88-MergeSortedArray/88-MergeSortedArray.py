# Last updated: 24/08/2026, 16:30:24
1# Definition for singly-linked list.
2# class ListNode(object):
3#     def __init__(self, val=0, next=None):
4#         self.val = val
5#         self.next = next
6class Solution(object):
7    def addTwoNumbers(self, l1, l2):
8        dummy = ListNode(0)
9        curr = dummy
10        carry = 0
11
12        while l1 != None or l2 != None or carry != 0:
13            val1 = l1.val if l1 != None else 0
14            val2 = l2.val if l2 != None else 0
15
16            total = val1 + val2 + carry
17
18            carry = total // 10
19            digit = total % 10
20
21            curr.next = ListNode(digit)
22            curr = curr.next
23
24            if l1 != None:
25                l1 = l1.next
26
27            if l2 != None:
28                l2 = l2.next
29
30        return dummy.next
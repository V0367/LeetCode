# Last updated: 20/08/2026, 11:45:34
1class Solution(object):
2    def moveZeroes(self, nums):
3        """
4        :type nums: List[int]
5        :rtype: None Do not return anything, modify nums in-place instead.
6        """
7        position = 0
8        n = len(nums)
9        for x in nums:
10            if x!=0:
11                nums[position] = x
12                position+=1
13            
14        for i in range(position,n):
15            nums[i] = 0
16
17        return nums
18        
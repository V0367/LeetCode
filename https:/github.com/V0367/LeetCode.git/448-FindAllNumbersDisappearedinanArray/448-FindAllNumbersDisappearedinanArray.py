# Last updated: 20/08/2026, 12:11:16
1class Solution(object):
2    def removeDuplicates(self, nums):
3        """
4        :type nums: List[int]
5        :rtype: int
6        """
7        if not nums:
8            return 0
9
10        position = 1
11        for i in range(1,len(nums)):
12            if nums[i]!=nums[position-1]:
13                nums[position] = nums[i]
14                position+=1
15        return position 
16
17        
18        
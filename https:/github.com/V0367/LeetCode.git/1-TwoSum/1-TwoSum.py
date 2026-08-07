# Last updated: 07/08/2026, 15:40:45
class Solution(object):
    def twoSum(self, nums, target):
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                if nums[i]+nums[j]==target:
                    return [i,j]
        

        obj = Solution()
        n = int(input("Enter the length of array : "))
        nums = list(map(int, input("Enter numbers: ").split()))

        target = int(input("Enter target sum:"))
        print(obj.twoSum)
        
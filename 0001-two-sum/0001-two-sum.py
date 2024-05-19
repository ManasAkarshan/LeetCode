class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

        mp = {}

        for i in range(len(nums)):
            if(target-nums[i] in mp):
                return [mp[target-nums[i]], i]
            
            else:
                mp.update({nums[i] : i})
        
        return [-1,-1]
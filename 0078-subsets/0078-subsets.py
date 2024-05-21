class Solution:
    def helper(self, ind, nums, temp, ans):
        if(ind == len(nums)):
            ans.append(temp[:])
            return

        if(ind > len(nums)):
            return
        
        # take
        temp.append(nums[ind])
        self.helper(ind+1, nums, temp, ans)
        temp.pop()

        # notTake
        self.helper(ind+1, nums, temp, ans)
    
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []

        self.helper(0, nums, [], ans)

        return ans;
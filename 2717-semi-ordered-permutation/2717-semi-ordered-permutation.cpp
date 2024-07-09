class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int smallInd, mini=INT_MAX, maxi=INT_MIN, largeInd, ans=0;

        for(int i=0; i<nums.size(); i++){
            if(mini>nums[i]) {smallInd = i+1; mini = nums[i];}
            if(maxi<nums[i]){ largeInd = i+1; maxi = nums[i];}
        }

        ans += smallInd - 1;
        ans += nums.size() - largeInd;

        if(smallInd > largeInd) ans -= 1;

        return ans;
    }
};
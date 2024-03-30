class Solution {
public:
    int rec(int ind, vector<int>& nums){
        if(ind == nums.size()-1) return true;
        if(ind>=nums.size()) return false;

        for(int i=1; i<=nums[ind]; i++){
            bool ch = rec(ind+i, nums);
            if(ch) return true;
        }
        return false;
    }

    
    bool canJump(vector<int>& nums) {
        // return rec(0, nums);
        int n = nums.size();

        vector<int> dp(n, -1);
        return memo(0, nums, dp)
    }
};
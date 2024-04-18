class Solution {
public:
    int rec(int ind, vector<int>& nums, int target, int sum){
        if(ind == nums.size()){
            if(sum == target) return 1;
            else return 0;
        }

        //add
        sum += nums[ind];
        int add = rec(ind+1, nums, target, sum);
        sum -= nums[ind];

        //sub
        sum -= nums[ind];
        int sub = rec(ind+1, nums, target, sum);

        return add + sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return rec(0, nums, target, 0);
    }
};
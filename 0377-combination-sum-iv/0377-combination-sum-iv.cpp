class Solution {
public:
    void bt(int ind, vector<int>& nums, int target, int& ans, int sum){
        if(sum==target){
            ans += 1;
            return;
        }
        if(sum>target) return;

        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            bt(i, nums, target, ans, sum);
            sum-=nums[i];
        }
    }
    int combinationSum4(vector<int>& nums, int target) {
        int ans = 0;
        bt(0, nums, target, ans, 0);
        return ans;
    }
};
class Solution {
public:
    void helper2(int ind, vector<int> &nums, set<vector<int>> &ans){
        if(ind == nums.size()){
            ans.insert(nums);
            return;
        }

        for(int i=ind; i<nums.size(); i++){
            swap(nums[ind], nums[i]);
            helper2(ind+1, nums, ans);
            swap(nums[ind], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        vector<vector<int>> realAns;
        helper2(0, nums, ans);

        for(auto it:ans) realAns.push_back(it);

        return realAns;
    }
};
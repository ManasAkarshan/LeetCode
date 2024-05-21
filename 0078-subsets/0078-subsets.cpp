class Solution {
public:
    void helper(int ind, vector<vector<int>> &ans, vector<int> ds, int n, vector<int> nums){
        if(ind==n){
            ans.push_back(ds);
            return;
        }
        // NOT TAKE
        helper(ind+1, ans, ds, n, nums);

        // TAKE
        ds.push_back(nums[ind]);
        helper(ind+1, ans, ds, n, nums);
        // ds.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();

        helper(0, ans, ds, n, nums);
        return ans;
    }
};
class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>> &ans, vector<int> vis, vector<int> temp){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(!vis[i]){
                vis[i] = 1;
                temp.push_back(nums[i]);
                helper(nums, ans, vis, temp);
                temp.pop_back();
                vis[i] = 0;
            }
        }
    }   
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> vis(nums.size(), 0);
        helper(nums, ans, vis, temp);
        return ans;
    }
};
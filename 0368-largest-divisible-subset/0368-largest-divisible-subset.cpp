class Solution {
public:
    vector<int> ans;
    void solve(int ind, int prev, vector<int> nums, vector<int> &temp, vector<int> &dp){
        if(ind == nums.size()) {
            if(temp.size()>ans.size()) ans = temp;
            return;
        }

        //take 
        if((nums[ind]%prev == 0 || prev%nums[ind] == 0) && dp[ind] < (int)temp.size()+1){
            dp[ind] = temp.size()+1;
            temp.push_back(nums[ind]);
            solve(ind+1, max(prev,nums[ind]), nums, temp, dp);
            temp.pop_back();
        }

        //notTake

        solve(ind+1, prev, nums, temp, dp);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<int> dp(nums.size(),-1);
        solve(0, 1, nums, temp, dp);
        return ans;
    }
};
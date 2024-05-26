class Solution {
public:
    void solve(int ind, vector<int>& nums, set<vector<int>> &s,vector<int> temp){
        if(ind >= nums.size()) {
            sort(temp.begin(), temp.end());
            s.insert(temp);
            return;
        }

        // take
        temp.push_back(nums[ind]);
        solve(ind+1, nums, s, temp);
        temp.pop_back();

        // notTake
        solve(ind+1, nums, s, temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> s;
        vector<vector<int>> ans;

        solve(0, nums, s, {});

        for(auto it : s){
            ans.push_back(it);
        }

        return ans;
    }
};
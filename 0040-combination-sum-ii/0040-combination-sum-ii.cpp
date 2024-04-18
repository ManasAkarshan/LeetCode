class Solution {
public:
    void helper(int ind, vector<int>& candidates, vector<vector<int>>& ans, vector<int> ds, int target){
        if(target == 0) {
            ans.push_back(ds);
            return;
        }

        for(int i=ind; i<candidates.size(); i++){
            if(i>ind && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            ds.push_back(candidates[i]);
            helper(i+1, candidates, ans, ds, target-candidates[i]);
            ds.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds; 

        helper(0, candidates, ans, ds, target);
        return ans;
    }
};
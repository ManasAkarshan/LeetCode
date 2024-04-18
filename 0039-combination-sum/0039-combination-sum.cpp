class Solution {
public:
    void bt(int ind, vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int> temp, int sum){
        if(ind == candidates.size()) return;
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        if(sum>target) return;

        for(int i=ind; i<candidates.size(); i++){
            temp.push_back(candidates[i]);
            sum+=candidates[i];
            bt(i, candidates, target, ans, temp, sum);
            sum-=candidates[i];
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        bt(0, candidates, target, ans, {}, 0);
        return ans;
    }
};
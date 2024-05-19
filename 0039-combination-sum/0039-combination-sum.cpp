class Solution {
public:
    void helper(int ind, vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int> temp, int sum){
        if(sum == target){
            ans.push_back(temp);
            return;
        }
        if(target < sum) return;
        
        for(int i = ind; i<candidates.size(); i++){
            temp.push_back(candidates[i]);
            helper(i, candidates, target, ans, temp, sum+candidates[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(0, candidates, target, ans, temp, 0);
        return ans;
    }
};
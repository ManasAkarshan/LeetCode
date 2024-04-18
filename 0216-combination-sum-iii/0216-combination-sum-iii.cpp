class Solution {
public:
    void bt(int ind, vector<vector<int>>& ans, vector<int> temp, int sum, int tar, int k){
        if(sum == tar){
            if(temp.size() == k) ans.push_back(temp);
            return;
        }
        if(ind>9) return;

        // pick 
        sum += ind;
        temp.push_back(ind);
        bt(ind+1, ans, temp, sum, tar, k);
        sum -= ind;
        temp.pop_back();

        // not pick
        bt(ind+1, ans, temp, sum, tar, k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        bt(1, ans, {}, 0, n, k);
        return ans;
    }
};
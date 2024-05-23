class Solution {
public:
    void solve(int ind, int n, int k, vector<int> temp, vector<vector<int>> &ans){
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }
        if(ind > n) return;

        for(int i = ind; i<=n; i++){
            temp.push_back(i);
            solve(i+1, n, k, temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;

        solve(1, n, k, {}, ans);
        return ans;
    }
};
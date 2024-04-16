class Solution {
public:
    void sol(int n, vector<vector<int>> &ans, vector<int> temp, int ind, int k){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        if(ind > n) return;

        for(int i=ind; i<=n; i++){
            temp.push_back(i);
            sol(n, ans, temp, i+1, k);
            temp.pop_back();
        }

    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        sol(n, ans, {}, 1, k);
        return ans;
    }
};
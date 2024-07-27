class Solution {
public:
    pair<int,int> count(string s){
        int o=0,z=0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '1') o++;
            else z++;
        }

        return {z, o};
    }
    // int rec(int ind, vector<string>& strs, int m, int n){
    //     if(ind >= strs.size()) return 0;
    //     if(m<0 || n<0) return 0;

    //     // take
    //     int take = 0;
    //     pair<int,int> cnt = count(strs[ind]);
    //     if(m-cnt.first >= 0 && n-cnt.second>=0) take = 1 + rec(ind+1, strs, m-cnt.first, n-cnt.second);

    //     // notTake
    //     int notTake = rec(ind+1, strs, m, n);


    //     return max(take, notTake);
    // }

    int memo(int ind, vector<string>& strs, int m, int n, vector<vector<vector<int>>> &dp){
        if(ind >= strs.size()) return 0;
        if(m<0 || n<0) return 0;
        if(dp[ind][m][n] != -1) return dp[ind][m][n];

        // take
        int take = 0;
        pair<int,int> cnt = count(strs[ind]);
        if(m-cnt.first >= 0 && n-cnt.second>=0) take = 1 + memo(ind+1, strs, m-cnt.first, n-cnt.second, dp);

        // notTake
        int notTake = memo(ind+1, strs, m, n, dp);


        return dp[ind][m][n] = max(take, notTake);

    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        // return rec(0, strs, m, n);
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m+1, vector<int>(n+1,-1)));

        return memo(0, strs, m, n, dp);
    }
};
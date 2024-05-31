class Solution {
public:
    int solve(vector<int>& coins, int amount, int ind, vector<vector<int>>& dp){
        if(amount == 0) return 0;
        if(ind >= coins.size()) return 1e7;
        if(amount < 0) return 1e7;
        if(dp[amount][ind] != -1) return dp[amount][ind] ;

        //take
        int take = 1 + solve(coins, amount-coins[ind], ind, dp);

        //notTake
        int notTake = solve(coins, amount, ind+1, dp);

        return dp[amount][ind] =  min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(amount+1, vector<int>(coins.size(), -1));
        int ans = solve(coins, amount, 0, dp);
        return ans == 10000000 ? -1 : ans;
    }
};
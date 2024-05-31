class Solution {
public:
    // int rec(vector<int>& coins, int ind, int amount){
    //     if(ind == 0){
    //         if(amount%coins[ind] == 0) return amount/coins[ind];
    //         else return 1e8;
    //     }

    //     if(amount<0) return 1e8;

    //     int notTake = rec(coins, ind-1, amount);

    //     int take = INT_MAX;
    //     if(coins[ind]<=amount) take = 1 + rec(coins, ind, amount-coins[ind]);

    //     return min(take, notTake);
    // }

    int memo(vector<int>& coins, int ind, int amount, vector<vector<int>> &dp){
        if(ind == 0){
            if(amount%coins[ind] == 0) return amount/coins[ind];
            else return 1e8;
        }

        if(amount<0) return 1e8;
        if(dp[ind][amount] != -1) return dp[ind][amount];

        int notTake = memo(coins, ind-1, amount, dp);

        int take = INT_MAX;
        if(coins[ind]<=amount) take = 1 + memo(coins, ind, amount-coins[ind], dp);

        return dp[ind][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // int ans = rec(coins, n-1, amount);
        // return ans == 1e8 ? -1 : ans;

        vector<vector<int>> dp(n, vector<int>(amount+1, -1));

        int ans = memo(coins, n-1, amount, dp);
        return ans == 1e8 ? -1 : ans;
    }
};
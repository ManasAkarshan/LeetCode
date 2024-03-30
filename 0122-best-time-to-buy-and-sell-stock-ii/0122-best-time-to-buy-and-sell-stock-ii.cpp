class Solution {
public:
    // int rec(int ind, int buy, vector<int>& prices){
    //     if(ind == prices.size()) return 0;

    //     if(buy == 1){
    //         return max((-prices[ind] + rec(ind+1, 0, prices)), (rec(ind+1, 1, prices)));
    //     }
    //     else {
    //         return max((prices[ind] + rec(ind+1, 1, prices)), rec(ind+1, 0, prices));
    //     }
    // }

    // if buy -> 1 then we can only buy/not else we can only sell/not
    int memo(int ind, int buy, vector<int>& prices,vector<vector<int>> &dp){
        if(ind == prices.size()) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];

        if(buy == 1){
            return dp[ind][buy] = max((-prices[ind] + memo(ind+1, 0, prices, dp)), (0 + memo(ind+1, 1, prices, dp)));
        }
        else {
            return dp[ind][buy] = max((prices[ind] + memo(ind+1, 1, prices, dp)), memo(ind+1, 0, prices, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // return rec(0, 1, prices);
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return memo(0, 1, prices, dp);


        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for(int i=0; i<2; i++) dp[n][i] = 0;

        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<2; buy++){
                if(buy==1){
                    dp[i][buy] = max((-prices[i] + dp[i+1][0]), (0 + dp[i+1][1]));
                }
                else{
                    dp[i][buy] = max((prices[i] + dp[i+1][1]), (0 + dp[i+1][0]));
                }
            }
        }
        return dp[0][1];
    }
};
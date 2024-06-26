class Solution {
public:
    int memo(int n, vector<int> &dp){
        if(n==1 || n==2) return 1;
        if(n==0) return 0;
        if(dp[n] != -1) return dp[n];

        return dp[n] = memo(n-1, dp) + memo(n-2, dp) + memo(n-3, dp);
    }
    int tribonacci(int n) {
        // return rec(n);

        vector<int> dp(n+1, -1);
        return memo(n, dp);
    }
};
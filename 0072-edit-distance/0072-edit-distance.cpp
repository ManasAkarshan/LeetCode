class Solution {
public:
    int memo(string s, string t, int i, int j, vector<vector<int>> &dp){
        if(i<0) return j+1;     // j+1 insert operations
        if(j<0) return i+1;     // i+1 delete operations

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]) return dp[i][j] = memo(s, t, i-1, j-1, dp);

        else return dp[i][j] = min(min((1+memo(s, t, i, j-1, dp)), (1+memo(s, t, i-1, j, dp))), (1+memo(s, t, i-1, j-1, dp)));
                                       //     insert                    delete                       replace
    } 
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        // return memo(word1, word2, n, m);
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return memo(word1, word2, n-1, m-1, dp);

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=0; i<=n; i++) dp[i][0] = i;
        for(int j=1; j<=m; j++) dp[0][j] = j;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(min(1+dp[i][j-1], 1+dp[i-1][j]), 1+dp[i-1][j-1]);
            }
        }
        return dp[n][m];
    }
};
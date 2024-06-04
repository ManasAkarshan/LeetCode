class Solution {
public:
    int solve(int i, int j, vector<vector<char>>& matrix, vector<vector<int>> &dp){
        if(i>=matrix.size() || i<0 || j >= matrix[0].size() || j < 0) return 0;
        if(matrix[i][j] == '0') return dp[i][j] = 0;
        if(dp[i][j] != -1) return dp[i][j];

        int bottom = solve(i+1, j, matrix, dp);
        int right = solve(i, j+1, matrix, dp);
        int diag = solve(i+1, i+1, matrix, dp);

        int len = 1 + min(bottom, min(right, diag));

        return dp[i][j] = len*len;
        
    }   
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                ans = max(ans, solve(i, j, matrix, dp));
            }
        }
        return ans;
    }
};
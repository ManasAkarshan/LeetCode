class Solution {
public:
    // copy tabhi karo agar kuch paste kiye ho 

    int solve(int n, string txt, string copy, bool isCopy, vector<vector<int>> &dp){
        if(txt.size() == n) return 1;
        if(txt.size() > n) return 1e5;
        if(dp[txt.size()][copy.size()] != -1) return dp[txt.size()][copy.size()];

        int cpy = 1e5;
        if(!isCopy) cpy = 1 + solve(n, txt, txt, 1, dp);

        int paste = 1 + solve(n, txt+copy, copy, 0, dp);


        return dp[txt.size()][copy.size()] = min(cpy, paste);
    }
    int minSteps(int n) {
        if(n==1) return 0;

        vector<vector<int>> dp(1001, vector<int>(1001, -1));
        return solve(n, "A", "A", 1, dp);
    }
};
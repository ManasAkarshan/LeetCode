class Solution {
public:
    bool solve(vector<int>& piles, int start, int end, int alice, int total, bool at, vector<vector<int>> &dp){
        if(start>end){
            return alice > (total-alice);
        }
        if(dp[start][end] != -1) return dp[start][end];

        // takeStart
        if(at) alice += piles[start];
        bool takeStart = solve(piles, start+1, end, alice, total, !at, dp);
        if(at) alice -= piles[start];

        // takeEnd
        if(at) alice += piles[end];
        bool takeEnd = solve(piles, start, end-1, alice, total, !at ,dp);
        if(at) alice -= piles[end];

        return dp[start][end] = takeStart || takeEnd;
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int sum = 0;
        for(int i=0; i<piles.size(); i++) sum += piles[i];

        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(piles, 0, piles.size()-1, 0, sum, true, dp);
    }
};
class Solution {
public:
    // int rec(int ind, string s, int k, char temp){
    //     if(ind>=s.size()) return 0;

    //     // take
    //     int left = 0;
    //     if(temp == '#' || abs((int)temp - (int)s[ind]) <= k) {
    //         left = 1 + rec(ind+1, s, k, s[ind]);
    //     }

    //     // notTake
    //     int right = rec(ind+1, s, k, temp);

    //     return max(left, right);
    // }
    int memo(int ind, string s, int k, char temp, vector<vector<int>>& dp){
        if(ind>=s.size()) return 0;
        if(dp[ind][(int)temp] != -1) return dp[ind][(int)temp];

        // take
        int left = 0;
        if(temp == '#' || abs((int)temp - (int)s[ind]) <= k) {
            left = 1 + memo(ind+1, s, k, s[ind], dp);
        }

        // notTake
        int right = memo(ind+1, s, k, temp, dp);

        return dp[ind][(int)temp] = max(left, right);
    }
    int longestIdealString(string s, int k) {
        // int ans = rec(0, s, k, '#');
        // vector<vector<int>> dp(s.size()+1, vector<int>(134, -1));
        // int ans = memo(0, s, k, '#', dp);
        int n = s.length()-1;
        vector<vector<int>> dp(n+2,vector<int>(27,0)); 
        // return f(n,s,'{',k,dp);

        //Tabulation
        for(int idx=n; idx>=0; idx--){
            for(int prev=0; prev<=26; prev++){
                int take=0,nottake=0;
                nottake = dp[idx+1][prev];
                if(prev == 0 || abs(s[idx]-'a'+1 - prev) <= k){
                    take = 1+ dp[idx+1][s[idx]-'a'+ 1];
                }
                dp[idx][prev] = max(take , nottake);
            }
        }
        return dp[0][0];
    }
};
class Solution {
public:
    // int rec(int i, string s, int n){
    //     if(i==n) return 1;

    //     if(s[i] == '0') return 0;

    //     int ith_i_plus_1th = 0;
    //     int only_ith = rec(i+1, s, n);

    //     if(i+1<n){
    //         if(s[i] == '1' || s[i] == '2' && s[i+1] <= '6') 
    //             ith_i_plus_1th = rec(i+2 ,s, n);
    //     }

    //     return ith_i_plus_1th + only_ith;
    // }
    int memo(int i, string s, int n, vector<int> & dp){
        if(i==n) return dp[i] = 1;

        if(s[i] == '0') return dp[i] = 0;

        if(dp[i] != -1) return dp[i];

        int ith_i_plus_1th = 0;
        int only_ith = memo(i+1, s, n, dp);

        if(i+1<n){
            if(s[i] == '1' || s[i] == '2' && s[i+1] <= '6') 
                ith_i_plus_1th = memo(i+2 ,s, n, dp);
        }

        return dp[i] = ith_i_plus_1th + only_ith;
    }
    int numDecodings(string s) {
        int n = s.size();
        // return rec(0, s, n);
        vector<int> dp(101, -1);
        return memo(0, s, n, dp);
    }
};
class Solution {
public:
    // bool rec(string s, int ind, int open){
    //     if(ind == s.size()) return open == 0;

    //     bool ans = false;

    //     if(s[ind] == '(') ans |= rec(s, ind+1, open+1);
    //     else if(s[ind] == ')') ans |= rec(s, ind+1, open-1);
    //     else if(s[ind] == '*'){
    //         bool a = rec(s, ind+1, open+1); // * = (
    //         bool b = rec(s, ind+1, open);  // * = ""
    //         bool c = rec(s, ind+1, open-1);  // * = )

    //         ans = a || b|| c;
    //     }
    //     return ans;
    // }

    bool memo(string s, int ind, int open, vector<vector<int>> &dp){
        if(ind == s.size()) return open == 0;
        if(dp[ind][open] != -1) return dp[ind][open];

        bool ans = false;

        if(s[ind] == '(') ans |= memo(s, ind+1, open+1, dp);
        else if(s[ind] == ')') ans |= open>0 ? memo(s, ind+1, open-1, dp) : 0;
        else if(s[ind] == '*'){
            bool a = memo(s, ind+1, open+1, dp); // * = (
            bool b = memo(s, ind+1, open, dp);  // * = ""
            bool c = open>0 ? memo(s, ind+1, open-1, dp) : 0;  // * = )

            ans = a || b|| c;
        }
        
        return dp[ind][open] = ans;
    }

    bool checkValidString(string s) {
        // return rec(s, 0, 0);

        vector<vector<int>> dp(100, vector<int>(100, -1));
        return memo(s, 0, 0, dp);
    }
};
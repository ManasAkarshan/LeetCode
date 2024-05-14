class Solution {
public:
    int t[1001][1001];
    bool checkPal(string s, int l, int r){
         if(l >= r) 
            return 1;

        if(t[l][r] != -1){
            return t[l][r];
        }

        if(s[l] == s[r]) {
            return t[l][r] = checkPal(s, l+1, r-1);
        }

        return t[l][r] = false;
    }

    string longestPalindrome(string s) {
        int stPt = 0;
        int len = INT_MIN;
        memset(t, -1, sizeof(t));

        for(int i=0; i<s.size(); i++){ 
            for(int j=i; j<s.size(); j++){
                if(checkPal(s, i, j)){
                    if(j-i+1 > len){
                        len = j-i+1;
                        stPt = i;
                    }
                }
            }
        }

        return s.substr(stPt, len);
    }
};
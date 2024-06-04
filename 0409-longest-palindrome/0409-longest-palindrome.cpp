class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int, int> mp;

        for(int i=0; i<s.size(); i++){
            mp[s[i]-'a']++;
        }

        int ans=0;
        bool odd = false;

        for(auto it:mp){
            ans += (it.second/2)*2;
            if(it.second%2 == 1) odd = 1;
        }

        if(odd) ans += 1;

        return ans;
    }
};
class Solution {
public:
    string reverseWords(string s) {
        int i=0, j = s.size()-1;

        while(s[i] == ' ') i++;
        while(s[j] == ' ') j--;
        string a;
        string ans;

        while(i<=j){
            if(s[j] == ' ') {
                reverse(a.begin(), a.end());
                ans += a; a = "";
                ans += " ";
                while(s[j] == ' ') j--;
            }
            else {
                a += s[j];
                j--;
            }
        }
        reverse(a.begin(), a.end());
        ans += a;
        return ans;
    }
};
class Solution {
public:
    int lengthOfLastWord(string s) {
        int j = s.size()-1;
        while(s[j] == ' ') j--;
        string a;

        while(j >= 0){
            if(s[j] == ' ') return a.size();
            a += s[j]; j--;
        }
        return a.size();
    }
};
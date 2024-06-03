class Solution {
public:
    int appendCharacters(string s, string t) {
        int cnt = 0, temp = 0;
        int i = 0, j = 0;

        while(i<s.size() && j<t.size()){
            if(s[i] == t[j]){
                temp++;
                j++;
            }
            i++;
        }
        return t.size()-temp;
    }
};
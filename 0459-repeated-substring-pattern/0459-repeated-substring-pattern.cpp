class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int i=1; i<s.size(); i++){
            string sub = s.substr(0, i);
            string temp = "";
            while(temp.size()<=s.size()){
                temp += sub;
                if(temp == s) return true;
            }
        }
        return false;
    }
};
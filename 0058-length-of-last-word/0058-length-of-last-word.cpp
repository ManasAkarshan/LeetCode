class Solution {
public:
    int lengthOfLastWord(string s) {
        string temp = "";
        string lw;
        for(int i=0; i<s.size(); i++){
            char st = s[i];
            if(st == ' '){
                if(temp != ""){
                    lw = temp;
                    temp = "";
                }
                else{
                    continue;
                }
            }
            else{
                temp += st;
            }
        }
        if(temp != "") lw = temp;
        return lw.size();
    }
};
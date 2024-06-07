class Solution {
public:
    string replaceWords(vector<string>& dict, string sen) {
        string temp = "";
        string ans;
        int i=0;
        unordered_map<string, bool> mp;
        for(auto s:dict) mp[s] = true;

        while(i<sen.size()){
            if(sen[i] == ' ') {
                if(ans != "") ans += " ";
                if(temp != "") {
                    ans += temp;
                    temp = "";
                }
            }
            else{
                temp += sen[i];

                if(mp.find(temp) != mp.end()){
                    if(ans != "") ans += " ";
                    ans += temp;
                    temp = "";
                    while(i<sen.size() && sen[i] != ' ') i++;
                }
            }
            i++;
        }
        if(temp != "") {
            if(ans != "") ans += " ";
            ans += temp;
        }
        return ans;
    }
};
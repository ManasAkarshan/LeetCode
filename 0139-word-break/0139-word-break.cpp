class Solution {
public: 
    bool helper(int ind, string s, unordered_map<string, int> dict){
        if(ind >= s.size()) return true;
        if(dict.find(s) != dict.end()) return true;

        string temp;
        for(int i=1; i<s.size(); i++){
            temp = s.substr(ind, i);
            if(dict.find(temp) != dict.end() && helper(ind+i, s, dict)) return true;
        }

        return false;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> dict;

        for(int i=0; i<wordDict.size(); i++) dict[wordDict[i]] = 1;

        return helper(0 ,s, dict);
    }
};
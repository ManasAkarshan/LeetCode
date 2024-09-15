class Solution {
public:
    bool isValid(int len, string s){
        vector<int> freq(26, 0);
        for(int i=0; i<len; i++){
            freq[s[i]-'a']++;
        }

        for(int i=len; i<s.size(); i+=len){
            vector<int> newFreq(26, 0);
            for(int j=i; j<i+len; j++){
                newFreq[s[j]-'a']++;
            }
            for(int j=0; j<26; j++){
                if(newFreq[j] != freq[j]) return false;
            }
        }

        return true;
    }
    int minAnagramLength(string s) {
        int n = s.size();

        for(int i=1; i<=s.size(); i++){
            if(n%i == 0 && isValid(i, s)) return i;
        }

        return s.size();
    }
};
class Solution {
public:
    bool allZero(vector<int> ch){
        for(int i=0; i<ch.size(); i++){
            if(ch[i] != 0) return false;
        }

        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> ch(26, 0);
        int n = s.size();
        vector<int> ans;

        for(int i=0; i<p.size(); i++){
            ch[p[i] - 'a']++;
        }

        int i=0, j=0;

        while(i<n){
            ch[s[i] - 'a']--;

            while(i-j+1 == p.size()){
                if(allZero(ch)) ans.push_back(j);

                ch[s[j] - 'a']++;
                j++;
            }

            i++;
        }

        return ans;
    }
};
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        vector<int> ans;

        for(int i=0; i<s.size(); i++){
            mp[s[i]] = i;
        }
        int last = mp[s[0]], prev = 0;

        for(int i=0; i<s.size(); i++){
            last = max(last, mp[s[i]]);
            if(i == last) {
                ans.push_back(last-prev+1);
                prev = last+1;
            }
            last = max(last, mp[s[i]]);
        }

        return ans;
    }
};
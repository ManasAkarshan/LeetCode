class Solution {
public:
    string oddString(vector<string>& words) {
        int n = words.size();
        
        vector<string> arr(n-1);
        unordered_map<string, string> m;
        
        for(int a=0; a<n; a++){
            string s = words[a];
            string temp = "";
            for(int i=0; i<s.size()-1; i++){
                int p = int(s[i+1]) - int(s[i]);
                temp += to_string(p);
                temp += ".";
            }
            arr.push_back(temp);
            m[temp] = s; 
        }

        unordered_map<string, int> mp;

        for(int i=0; i<arr.size(); i++){
            mp[arr[i]]++;
        }

        for(auto it : mp){
            if(it.second == 1) return m[it.first];
        }

        return "";        
    }
};
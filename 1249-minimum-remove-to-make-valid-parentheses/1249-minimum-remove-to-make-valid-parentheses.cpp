class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> st;
        unordered_map<int, bool> mp;
        string ans = "";

        for(int i=0; i<s.size(); i++){
            if(s[i] == '(') st.push({s[i], i});
            else if(s[i] == ')') {
                if(!st.empty()) {
                    if(st.top().first == '(') st.pop();
                    else st.push({s[i], i});
                }
                else{
                    st.push({s[i], i});
                }
            }
        }
        while(!st.empty()){
            mp[st.top().second] = true;
            st.pop();
        }

        for(int i=0; i<s.size(); i++){
            if(mp[i] == 1) continue;
            ans += s[i];
        }
        return ans;
    }
};
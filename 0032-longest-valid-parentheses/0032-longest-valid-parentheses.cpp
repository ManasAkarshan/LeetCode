class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        

        for(int i=0; i<s.size(); i++){
            stack<char> st;
            for(int j=i; j<s.size(); j++){
                if(!st.empty() && s[j] == ')' && st.top() == '('){
                    st.pop();
                    if(st.empty()) ans = max(ans, j-i+1);
                }
                else{
                    st.push(s[j]);
                }
            }
        }

        return ans;
    }
};
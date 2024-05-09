class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string ans = "";
        int i=0;

        while(i<path.size()){
            if(path[i] == '/') {
                string temp = "";
                temp += path[i];
                if(st.empty() || st.top() != "/") st.push(temp);
                cout<<st.top()<<" ";
                i++;
            }
            else{
                string temp = "";
                while(i<path.size() && path[i] != '/') {
                    temp += path[i];
                    i++;
                }
                if(temp == ".."){
                    st.pop();
                    if(!st.empty()) st.pop();
                }
                else if((temp == "/" && st.top() == "/") || temp == ".") continue;
                else st.push(temp);
            }
        }
        
        if(st.top() == "/" && st.size()>1) st.pop();

        while(!st.empty()){
            string temp = st.top();
            reverse(temp.begin(), temp.end());
            ans += temp;
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
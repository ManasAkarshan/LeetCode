class Solution {
public:
    void fn(stack<string> &st){
        string temp = "";

        while(st.top() != "["){
            temp += st.top();
            st.pop();
        }
        cout<<temp<<" ";
        st.pop();

        string n = "";
        bool ch = 1;
        while(ch && !st.empty()){
            string t = st.top();
            for(int i=0; i<t.size(); i++) {
                if(isdigit(t[i])) {
                    n += t[i];
                    cout<<n<<" ";
                    st.pop();
                }
                else ch = 0;
            }
        }
        reverse(n.begin(), n.end());
        int num = stoi(n);
        cout<<num<<" ";
        for(int i=0; i<num; i++)st.push(temp);
    }

    string decodeString(string s) {
        int i=0; 
        stack<string> st;
        string temp = "";

        while(i<s.size()){
            if(s[i] == ']'){
                fn(st);
            }
            else{
                string t;
                t += s[i];
                st.push(t);
            }
            i++;
        }

        while(!st.empty()){
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};
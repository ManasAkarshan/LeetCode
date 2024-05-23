class Solution {
public:
    bool checkValid(string s){
        int open = 0;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '(') open++;
            if(s[i] == ')') open--;
            if(open<0) return false;
        }

        return open == 0;
    }

    void generate(vector<string> &ans, string s, int n){
        if(s.size() == 2*n) {
            if(checkValid(s)) ans.push_back(s);
            return;
        }

        s.push_back('(');
        generate(ans, s, n);
        s.pop_back();

        s.push_back(')');
        generate(ans, s, n);
        // s.pop_back();      dalo na dalo barabar
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(ans, "", n);

        return ans;
    }
};
class Solution {
public:
    bool isValid(string s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }

    void rec(string s, vector<string> temp, vector<vector<string>> &ans, int ind, int n){
        if(ind>=n) {
            if(temp.size()>0){
                ans.push_back(temp);
            }
            return;
        }

        for(int k=ind; k<n; k++){
            if(isValid(s, ind, k)){
                temp.push_back(s.substr(ind,k-ind+1));
                rec(s, temp, ans, k+1, n);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        rec(s, {}, ans, 0, s.size());
        return ans;
    }
};
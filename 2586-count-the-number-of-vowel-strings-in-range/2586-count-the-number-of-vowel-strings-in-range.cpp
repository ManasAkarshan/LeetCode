class Solution {
public:
    bool helper(vector<string>& words, int i){
        string s = words[i];
        string vow = "aeiou", f = "", l = "";
        f += s[0]; l += s[s.size()-1];
        cout<<f<<" "<<l<<" ";
        return (vow.find(f)<=10 && vow.find(l)<=10);
    }
    int vowelStrings(vector<string>& words, int left, int right) {
        int cnt = 0;
        for(int i=left; i<=right; i++){
            if(helper(words, i)) cnt++;
            cout<<cnt<<" ";
        }
        return cnt;
    }
};
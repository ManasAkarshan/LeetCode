class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cntDot = 0, ans = 0;
        for(auto it : logs){
            for(int i=0; i<it.size(); i++){
                if(it[i] == '.') cntDot++;
            }
            if(cntDot == 2) {if(ans>0) ans--;}
            else if(cntDot == 0) ans++;
            cntDot = 0;
        }

        return ans;
    }
};
class Solution {
public:
    bool check(string s){
        if(s.size() == 0) return 0;

        unordered_map<char, bool> mp;
        for(int i=0; i<s.size(); i++){
            if(mp.find(s[i]) != mp.end()) return false;
            mp[s[i]] = true;
        }

        return true;
    }
    int solve(int ind, vector<string> arr, string temp){
        if(ind == arr.size()){
            if(check(temp)) return temp.size();
            return 0;
        }

        // notTake  
        int notTake = solve(ind+1, arr, temp);

        
        // take
        int take = INT_MIN;
        if(check(temp+arr[ind])) take = solve(ind+1, arr, temp+arr[ind]);

        return max(take, notTake);
    }
    int maxLength(vector<string>& arr) {
        return solve(0, arr, "");
    }
};
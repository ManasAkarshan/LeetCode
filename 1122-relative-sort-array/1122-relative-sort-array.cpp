class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp;
        vector<int> ans;
        for(int i=0; i<arr1.size(); i++) mp[arr1[i]]++;
        for(int i=0; i<arr2.size(); i++){
            int k = mp[arr2[i]];
            for(int j=0; j<k; j++){
                ans.push_back(arr2[i]);
            }
            mp[arr2[i]]=0;
        }

        for(auto it:mp){
            int k = it.second;
            for(int i=0; i<k; i++) ans.push_back(it.first);
        }

        return ans;
    }
};
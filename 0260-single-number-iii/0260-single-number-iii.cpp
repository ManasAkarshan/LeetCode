class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;
        
        for(int i=0; i<nums.size(); i++){
            ++mp[nums[i]];
        }
        for(auto i:mp){
            if(i.second < 2){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int ans = 0;
        long long total = 0;
        for(int i=0; i<nums.size(); i++){
            total += nums[i];
        }

        long long sum = 0;
        for(int i=0; i<nums.size()-1; i++){
            sum += nums[i];
            if(sum >= (total-sum)) ans++;
        }

        return ans;
    }
};
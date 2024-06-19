class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // 1 1 2 2 3 7

        int ans = 0;

        for(int i=1; i<nums.size(); i++){
            if(nums[i] <= nums[i-1]){
                ans += nums[i-1] - nums[i] + 1;
                nums[i] += nums[i-1] - nums[i] + 1;
            }
        }

        return ans;
        
    }
};
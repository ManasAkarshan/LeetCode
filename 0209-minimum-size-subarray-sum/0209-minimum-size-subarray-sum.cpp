class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0, j=0, n = nums.size();
        int ans = INT_MAX, sum = 0;

        while(i<n && j<n){
            sum += nums[i];
            while(sum>=target){
                ans = min(ans, (1+(i-j)));
                sum -= nums[j]; j++;
            }
            i++;
        }

        return ans==INT_MAX ? 0 : ans;
    }
};
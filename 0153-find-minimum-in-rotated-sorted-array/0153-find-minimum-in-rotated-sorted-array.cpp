class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int high = n-1, low = 0, mid, ans = INT_MAX;

        // while(low<=high){
        //     mid = low + (high-low)/2;

        //     if(nums[low]<=nums[mid]){
        //         ans = min(ans, nums[low]);
        //         low = mid+1;
        //     }
        //     else{
        //         ans = min(ans, nums[mid]);
        //         high = mid - 1;
        //     }
        // }

        // BETTER

        while(low<=high){
            mid = low + (high-low)/2;

            if(nums[low]<=nums[high]){
                ans = min(ans, nums[low]);
                return ans;
            }
            if(nums[low]<=nums[mid]){
                ans = min(ans, nums[low]);
                low = mid+1;
            }
            else{
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};
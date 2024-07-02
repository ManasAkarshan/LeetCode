class Solution {
public:
    int check(vector<int> nums, int maxSum){
        int sub = 1, sum=0;

        for(int i=0; i<nums.size(); i++){
            if(sum+nums[i] <= maxSum){
                sum += nums[i];
            }
            else{
                sub++;
                sum = nums[i];
            }
        }

        return sub;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=-1, high = 0, ans = -1;

        for(int i=0; i<nums.size(); i++){
            low = max(low, nums[i]);
            high += nums[i];
        }

        while(low <= high){
            int mid = low +(high-low)/2;
            cout<<mid<<" ";

            if(check(nums, mid) > k) {
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return low;
    }
};
class Solution {
public:
    int findMax(vector<int>& nums){
        int maxi = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }
    int func(int mid, int h, vector<int>& nums){
        long long int th = 0;
        for(int i=0; i<nums.size(); i++){
            th += ceil(double(nums[i])/double(mid));
        }
        cout<<th;
        if(th<=h) return 1;
        else return 0;
    }

    int minEatingSpeed(vector<int>& nums, int h) {
        int low = 1, high = findMax(nums), mid;

        while(low<=high){
            mid = low + (high-low)/2;
            int ch = func(mid, h, nums);
            
            if(ch){
                high = mid-1;
            }
            else low = mid+1;
        }
        return low;
    }
};
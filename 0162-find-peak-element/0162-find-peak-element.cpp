class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i=1, j=nums.size()-2,mid;
        if(j == -1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[nums.size()-1] > nums[nums.size()-2]) return nums.size()-1;

        while(i<=j){
            mid = i + (j-i)/2;

            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;

            else if(nums[mid-1]<nums[mid] && nums[mid] < nums[mid+1]) i = mid+1;
            
            else j = mid-1;
        }

        return -1;
    }
};
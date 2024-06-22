class Solution {
public:
    int findLast(vector<int>& nums, int target){
        int i=0,j=nums.size()-1, mid, ans=-1;

        while(i<=j){
            mid = i + (j-i)/2;

            if(nums[mid] == target) {
                ans = mid;
                i = mid+1;
            }
            else if(nums[mid] > target) j = mid-1;
            else i = mid+1;
        }
        return ans;
    }
    int findFirst(vector<int>& nums, int target){
        int i=0,j=nums.size()-1, mid, ans=-1;

        while(i<=j){
            mid = i + (j-i)/2;

            if(nums[mid] == target) {
                ans = mid;
                j = mid-1;
            }
            else if(nums[mid] > target) j = mid-1;
            else i = mid+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;

        int first = findFirst(nums, target);
        int last = findLast(nums, target);

        ans.push_back(first);
        ans.push_back(last);

        return ans;
    }
};
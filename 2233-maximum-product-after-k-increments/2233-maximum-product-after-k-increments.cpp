class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0, n = nums.size()-1;

        while(i<n && k > 0){
            while(nums[i+1] > nums[i] && k>0){
                nums[i]++;
                k--;
            }
            i++;
        }

        while(k>0){
            nums[i]++;
            k--;
        }

        int ans = 1;
        for(auto it : nums){
            ans *= it;
        }

        return ans;
        
    }
};
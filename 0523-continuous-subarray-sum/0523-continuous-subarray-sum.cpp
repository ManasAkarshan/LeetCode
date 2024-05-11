class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        long long sum = nums[0], temp;
        int j;
        if(nums.size() == 1) return false;

        for(int i=1; i<nums.size(); i++){
            if(nums[i]==nums[i-1]) 
                if(nums[i]==0) 
                    return true;

            sum += nums[i];

            if(sum%k == 0) return true;

            j=0; 
            temp = sum;

            while(i-j>1 && temp>k){
                temp -= nums[j];
                if( temp%k == 0) return true;
                j++;
            }
        }

        return false;
    }
};
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size(), sum=0, ans=0;

        for(int i=0; i<n; i++){
            sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                if(sum%k == 0) ans++;
            }
        }

        return ans;
    }
};
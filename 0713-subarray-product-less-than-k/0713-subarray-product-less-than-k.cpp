class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0, j = 0, n = nums.size();
        int prd = 1, ans = 0;
        if(k<=1) return 0;

        while(i<n && j<n){
            prd *= nums[i];
            while(prd>=k ){
                prd = prd/nums[j]; 
                j++;
            }
            ans += 1 + (i-j);
            i++;
        }
        return ans;


        // for(int i=0; i<n; i++){
        //     long long int p = 1;
        //     for(int j=i; j<n; j++){
        //         p = p*nums[j];
        //         if(p<k) ans += 1;
        //         else j = n;  // break loop
        //     }
        // }

        // return ans;
    }
};
class Solution {
public:
    bool check(vector<int>& nums, int t, int mid){
        int temp=0;

        for(int i=0; i<nums.size(); i++){
            temp += ceil(double(nums[i])/double(mid));
        }
        cout<<mid<<"."<<temp<<" ";

        return temp <= t;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = INT_MIN, ans=-1;

        for(int i=0; i<nums.size(); i++) maxi = max(maxi, nums[i]);

        int i=1, j=maxi;

        while(i<=j){
            int mid = i+(j-i)/2;

            if(check(nums, threshold, mid)){
                ans = mid;
                j = mid-1;
            }
            else i = mid+1;
        }

        return ans;
    }
};
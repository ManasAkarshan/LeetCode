class Solution {
public:
    // int rec(vector<int>& nums1, vector<int>& nums2, int i1, int i2, int takenPrev){
    //     if(i1>=nums1.size() || i2>=nums2.size()) return 0;
    //     if(takenPrev && nums1[i1] != nums2[i2]) return 0;
 
    //     // TAKE 
  
    //     int take = INT_MIN;
    //     if(nums1[i1] == nums2[i2]) take = 1 + rec(nums1, nums2, i1+1, i2+1, 1);
            

    //     // not take
    //     int nt1 = INT_MIN, nt2 = INT_MIN;
    //     if(!takenPrev){
    //         nt1 =  rec(nums1, nums2, i1+1, i2, 0);
    //         nt2 = rec(nums1, nums2, i1, i2+1, 0);
    //     }

    //     return max(take, max(nt1, nt2));

    // }
    int rec(vector<int>& nums1, vector<int>& nums2, int i1, int i2, int takenPrev, vector<vector<int>> &dp){
        if(i1>=nums1.size() || i2>=nums2.size()) return 0;
        if(takenPrev && nums1[i1] != nums2[i2]) return 0;
        if(dp[i1][i2] != -1) return dp[i1][i2];
 
        // TAKE 
  
        int take = INT_MIN;
        if(nums1[i1] == nums2[i2]) take = 1 + rec(nums1, nums2, i1+1, i2+1, 1, dp);
            

        // not take
        int nt1 = INT_MIN, nt2 = INT_MIN;
        if(!takenPrev){
            nt1 =  rec(nums1, nums2, i1+1, i2, 0, dp);
            nt2 = rec(nums1, nums2, i1, i2+1, 0, dp);
        }

        return dp[i1][i2] = max(take, max(nt1, nt2));

    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), -1));
        return rec(nums1, nums2, 0, 0, 0, dp);
    }
};
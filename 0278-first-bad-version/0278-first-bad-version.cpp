// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int bs(int n){
        long long int left = 1, right = n;
        long long int ans = 0;

        while(left<=right){
            int mid = (left+right)/2;
            if(isBadVersion(mid) == 1){
                ans = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return ans;
    }
    int firstBadVersion(int n) {
        return bs(n);
    }
};
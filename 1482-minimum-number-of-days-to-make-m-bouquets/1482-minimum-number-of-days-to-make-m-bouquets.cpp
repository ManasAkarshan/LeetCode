class Solution {
public:
    int findMin(vector<int>& bloomDay){
        int mini = INT_MAX;
        for(int i=0; i<bloomDay.size(); i++){
            mini = min(mini, bloomDay[i]);
        }
        return mini;
    }
    int findMax(vector<int>& bloomDay){
        int maxi = INT_MIN;
        for(int i=0; i<bloomDay.size(); i++){
            maxi = max(maxi, bloomDay[i]);
        }
        return maxi;
    }
    int countB(vector<int> bloom, int day, int k){
        int count = 0, ans = 0;

        for(int i=0; i<bloom.size(); i++){
            if(bloom[i]<=day) count++;
            else{
                ans += (count/k);
                count = 0;
            }
        }
        ans += (count/k);
        return ans;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long int c = m*1LL * k*1LL;
        if(c>bloomDay.size()) return -1;

        int high = findMax(bloomDay), low = findMin(bloomDay), mid , ans = high;

        while(low<=high){
            mid = low + (high-low)/2;

            int ch = countB(bloomDay, mid, k);
            cout<<ch<<endl;

            if(ch>=m) {
                high = mid-1;
                ans = mid;
            }
            else low = mid+1;
        }
        return ans;
    }
};
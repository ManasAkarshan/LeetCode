class Solution {
public:
    int check(vector<int>& weights, int days, int mid){
        int load = 0, d = 1;
        for(int i=0; i<weights.size(); i++){
            if (weights[i] + load > mid){
                d++;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        if(d<=days) return 1;
        return 0;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = INT_MIN , high = 0, mid, ans;

        for(int i=0; i<weights.size(); i++){
            high += weights[i];
            low = max(low, weights[i]);
        }

        while(low<=high){
            mid = low + (high-low)/2;

            if(check(weights, days, mid)){
                high = mid - 1;
                ans = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
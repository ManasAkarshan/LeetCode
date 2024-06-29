class Solution {
public:
    bool check(vector<int>& weights, int days, int mid){
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
        int i=INT_MIN,j=0, ans=0;
        for(int a=0; a<weights.size(); a++) {
            j+= weights[a]; 
            i=max(i, weights[a]);
        }

        while(i<=j){
            int mid = i+(j-i)/2;

            if(check(weights, days, mid)){
                ans = mid;
                j=mid-1;
            }
            else i = mid+1;
        }

        return ans;
    }
};
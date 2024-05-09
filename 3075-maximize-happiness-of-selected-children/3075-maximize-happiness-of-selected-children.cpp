class Solution {
public:
    static bool comp(int a, int b){
        return a>b;
    }
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), comp);
        long long ans = 0;

        for(int i=0; i<k; i++){
            ans += (happiness[i]-i) > 0? happiness[i]-i : 0;
        }

        return ans;
    }
};
class Solution {
public:
    static bool comp(int a, int b){
        return a>b;
    }
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), comp);
        int j=0;
        long long ans = 0;

        for(int i=0; i<k; i++){
            ans += (happiness[j]-i) > 0? happiness[j]-i : 0;
            j++;
        }

        return ans;
    }
};
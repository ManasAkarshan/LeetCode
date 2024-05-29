class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len = 0, ans = 0;

        int i=0, j=0;
        long long cost = 0;

        while(i<s.size()){
            cost += abs(int(s[i])-int(t[i]));
            if(cost <= maxCost) len = max(len, i-j+1);
            i++;

            while(cost > maxCost && j<=i){
                cost -= abs(int(s[j])-int(t[j]));
                j++;
            }
        }

        return len;
    }
};
class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int i=0, j=0, ans = 0, cnt = 0;
        char prev = -10;

        while(i<word.size()){
            if(word[i] < prev){
                if(cnt == 5)ans = max(ans, (i-j));
                prev = word[i];
                cnt = 1;
                j = i;
            }
            else{
                if(word[i] != prev){
                    cnt++;
                }
                prev = word[i];
            }
            i++;
        }
        
        if(cnt == 5) ans = max(ans, (i-j));

        return ans;
    }
};
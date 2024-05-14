class Solution {
public:
    bool helper(int n){
        int sum = 0;
        while(n>0){
            sum += n%10;
            n = n/10;
        }

        return sum%2 == 0;
    }
    int countEven(int num) {
        int cnt = 0;
        for(int i=1; i<=num; i++){
            if(helper(i)) cnt++;
        }
        return cnt;
    }   
};
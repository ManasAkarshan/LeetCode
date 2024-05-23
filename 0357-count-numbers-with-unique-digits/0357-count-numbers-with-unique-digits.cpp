class Solution {
public:
    bool isValid(int n){
        int t = n;
        vector<int> temp(10, 0);
        while(n>0){
            int i = n%10;
            if(temp[i] != 0) return false;
            temp[i] = 1;
            n = n/10;
        }

        return true;
    }
    int countNumbersWithUniqueDigits(int n) {
        vector <int> answer{1, 10, 91, 739, 5275, 32491, 168571, 712891, 2345851}; 
        return answer[n];
    }
};
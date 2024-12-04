class Solution {
    public static int rec(int m, int n){
        if(m == 0 && n == 0){
            return 1;
        }
        if(m < 0 || n < 0) {
            return 0;
        }

        return rec(m-1, n) + rec(m, n-1);
    }
    public int uniquePaths(int m, int n) {
        return rec(m-1, n-1);
    }
}
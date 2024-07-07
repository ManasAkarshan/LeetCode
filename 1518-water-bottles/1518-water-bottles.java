class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0, prev = numBottles, extra, nw = 0;
        while(prev > 0){
            ans += prev;
            prev = (prev+nw)/numExchange;
            nw = prev%numExchange;
        }

        return ans;
    }
}
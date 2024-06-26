class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size(), cnt = 0;
        // while(tickets[k] > 0){
        //     for(int i=0; i<n; i++){
        //         if(tickets[i]>0) {
        //             tickets[i] = tickets[i]-1;
        //             cnt++;
        //             if(tickets[k] == 0) return cnt;
        //         }
        //     }
        // }
        // return cnt;

        for(int i=0; i<n; i++){
            if(i<=k) cnt += min(tickets[i], tickets[k]);
            else cnt += min(tickets[k]-1, tickets[i]);
        }
        return cnt;
    }
};
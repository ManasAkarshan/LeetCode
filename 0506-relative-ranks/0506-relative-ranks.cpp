class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq;
        int n = score.size(), cnt = 1;
        vector<string> ans(n);

        for(int i=0; i<n; i++){
            pq.push({score[i], i});
        }

        for(int i=0; i<n; i++){
            pair<int,int> temp = pq.top();
            pq.pop();
            if(i==0) ans[temp.second] = "Gold Medal";
            else if(i==1) ans[temp.second] = "Silver Medal";
            else if(i==2) ans[temp.second] = "Bronze Medal";
            else ans[temp.second] = to_string(i+1);
        }

        return ans;
    }
};
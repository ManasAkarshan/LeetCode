class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        if(m==1 && n==1) return 0;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0 ,0}});
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!pq.empty()){
            int diff = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if(r == m-1 && c == n-1) return diff;

            for(int i=0; i<4; i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if(nr>=0 && nr<m && nc>=0 && nc<n){
                    int newDiff = max(diff, abs(heights[r][c]-heights[nr][nc]));
                    if(newDiff < dist[nr][nc]) {
                        dist[nr][nc] = newDiff;
                        pq.push({newDiff, {nr, nc}});
                    }
                }
            }
        }
        return 0;
    }
};
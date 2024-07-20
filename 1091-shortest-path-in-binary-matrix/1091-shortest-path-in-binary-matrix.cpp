class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        int n = grid.size();
        if(grid[n-1][n-1] == 1) return -1;
        if(n==1 && grid[0][0] == 0) return 1;
        int ans = 1e9;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        queue<pair<int, pair<int, int>>> q;
        q.push({1,{0,0}});

        while(!q.empty()){
            int r = q.front().second.first;
            int c = q.front().second.second;
            int dis = q.front().first;
            q.pop();

            for(int i=-1; i<=1; i++){
                for(int j=-1; j<=1; j++){
                    int nr = r + i;
                    int nc = c + j;
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc] == 0  && dist[nr][nc]>dis + 1){
                        dist[nr][nc] = dis + 1;
                        if(nr == n-1 && nc == n-1) return dis + 1;
                        q.push({1+dis,{nr, nc}});
                    }
                }
            }
        }
        return -1;
    }
};
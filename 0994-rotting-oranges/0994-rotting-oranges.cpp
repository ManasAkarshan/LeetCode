class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int> ,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        int cntFresh = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                if(grid[i][j] == 1){
                    cntFresh++;
                }
            }
        }
        int time = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        int cnt = 0;

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();

            for(int i=0; i<4; i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == 1 && vis[nr][nc]!=2){
                    cnt++;
                    q.push({{nr, nc}, t+1});
                    vis[nr][nc] = 2;
                }
            }
        }
        if(cnt != cntFresh) return -1;
        return time;
    }
};
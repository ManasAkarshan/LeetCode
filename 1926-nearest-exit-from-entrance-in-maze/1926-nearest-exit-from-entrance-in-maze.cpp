class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int i = entrance[0], j = entrance[1];
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        queue<pair<pair<int,int>, int>> q;
        q.push({{i, j}, 0});
        vis[i][j] = 1;

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dis = q.front().second;
            q.pop();

            if(!(r==i && c==j)) if(r==0 || r==m-1 || c==0 || c==n-1) return dis;

            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};

            for(int i=0; i<4; i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if(nr<m && nr>=0 && nc<n && nc>=0 && !vis[nr][nc] && maze[nr][nc] == '.') {
                    q.push({{nr, nc}, dis+1});
                    vis[nr][nc] = 1;
                }
            }
        }
        return -1;
    }
};
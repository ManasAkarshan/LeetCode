class Solution {
public:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> grid){
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        grid[row][col]='0';
        int delta_row[] = {-1, 0, 1, 0};
        int delta_col[] = {0, 1, 0, -1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            // FOR ALL 8 DIRECTION
            // for(int delrow=-1; delrow<=1; delrow++){
            //     for(int delcol=-1; delcol<=1; delcol++){
            //         int nr = r + delrow;
            //         int nc = c + delcol;
                    // if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == '1' && !vis[nr][nc]){
                    //     vis[nr][nc] = 1;
                    //     q.push({nr, nc});
                    // }
            //     }
            // }
            for (int i = 0; i < 4; i++){
                int nr = r + delta_row[i];
                int nc = c + delta_col[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == '1' && !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0)); // n vector of size m with intitial value 0

        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(!vis[row][col] && grid[row][col] == '1' ){
                    cnt++;
                    bfs(row, col, vis, grid );
                }
            }
        }
        return cnt;
    }
};
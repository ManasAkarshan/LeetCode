class Solution {
public:
    bool solve(vector<vector<char>>& grid, int r, int c, char ch, int p1, int p2, vector<vector<int>>& vis){
        int m = grid.size();
        int n = grid[0].size();

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for(int i=0; i<4; i++){
            int nr = drow[i] + r;
            int nc = dcol[i] + c;

            if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == ch){
                if(vis[nr][nc] == 1){
                    if((nr != p1 || nc != p2)) return true;
                }
                else {
                    vis[nr][nc] = 1;
                    if(solve(grid, nr, nc, ch, r, c, vis)) return true;
                }
            }
        }

        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m+1, vector<int>(n+1, 0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(vis[i][j] == 0){
                    vis[i][j] = 1;
                    if(solve(grid, i, j, grid[i][j], i, j, vis)) return true;
                }
            }
        }

        return false;
    }
};
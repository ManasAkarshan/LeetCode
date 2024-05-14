class Solution {
public:
    int solve(vector<vector<int>>& grid, int r, int c){
        int ans = 0;

        int drow [] = {-1, 0, 1, 0};
        int dcol [] = {0, 1, 0, -1};
        int val = grid[r][c];
        grid[r][c] = 0;

        for(int i=0; i<4; i++){
            int nr = r + drow[i];
            int nc = c + dcol[i];
            int temp = val;
            if(nr<grid.size() && nr>=0 && nc<grid[0].size() && nc>=0 && grid[nr][nc] != 0) temp += solve(grid, nr, nc);
            ans = max(ans, temp);
        }   
        grid[r][c] = val;

        return ans;

    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] != 0) {
                    cout<<grid[i][j]<<" ";
                    ans = max(ans, solve(grid, i, j));
                }
            }
        }

        return ans;
    }
};
class Solution {
public: 
    int nonObs, ans ;
    void sol(vector<vector<int>> &grid, int i, int j, int nObs){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == -1) return;
        if(grid[i][j] == 2){
            if(nObs == nonObs) ans++;
            return;
        }

        int temp = grid[i][j];
        grid[i][j] = -1;
        int drow[] = {1, -1, 0, 0};
        int dcol[] = {0, 0, -1, 1};

        for(int x=0; x<4; x++){
            int nr = i + drow[x];
            int nc = j + dcol[x];

            sol(grid, nr, nc, nObs+1);
        }
        grid[i][j] = temp;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int x = 0, y = 0;
        nonObs = 0;
        ans = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1) {
                    x = i;
                    y = j;
                }
                if(grid[i][j] == 0) nonObs++;
            }
        }

        nonObs += 1;
        sol(grid, x, y, 0);
        return ans;
    }       
};
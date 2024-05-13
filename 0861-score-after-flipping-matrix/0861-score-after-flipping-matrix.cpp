class Solution {
public:
    void swapCol(vector<vector<int>>& grid, int row, int col){
        for(int i = 0; i<row; i++){
            grid[i][col] = !grid[i][col];
        }
    }

    int matrixScore(vector<vector<int>>& grid) {
        // Row Wise
        int m = grid.size(), n = grid[0].size(); //m(row) = 3, n(col) = 4;
        int ans = 0;

        for(int row=0; row<m; row++){
            if(grid[row][0] == 0){
                for(int col=0; col<n; col++) grid[row][col] = !grid[row][col];
            }
        }

        // Col Wise
        int col, row;
        for(col=n-1; col>=1; col--){
            int cnt = 0;
            for(row=0; row<m; row++){
                if(grid[row][col] == 0) cnt++;
            }
            if(cnt>m/2) swapCol(grid, row, col);
        }
        
        for(int i=0; i<m; i++){
            int temp = 0, to = 1;
            for(int j=n-1; j>=0; j--){
                temp += grid[i][j] * to;
                to *= 2;
            }
            ans += temp;
        }

        return ans;
    }
};
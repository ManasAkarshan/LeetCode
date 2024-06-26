class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &board, vector<vector<int>> &vis){
        int n = board.size(), m = board[0].size();
        vis[row][col] = 1;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for(int i=0; i<4; i++){
            int nr = row + drow[i];
            int nc = col + dcol[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc] == 1 && !vis[nr][nc]){
                dfs(nr, nc, board, vis);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n ,vector<int>(m, 0));

        // For first and last row
        for(int j=0; j<m; j++){
            if(board[0][j] == 1){
                dfs(0 , j , board , vis);
            }

            if(board[n-1][j] == 1){
                dfs(n-1, j, board, vis);
            }
        }

        // For first and last column
        for(int j=0; j<n; j++){
            if(board[j][0] == 1){
                dfs(j, 0 , board , vis);
            }

            if(board[j][m-1] == 1){
                dfs(j, m-1, board, vis);
            }
        }
        int ans = 0; 
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 1 && !vis[i][j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};
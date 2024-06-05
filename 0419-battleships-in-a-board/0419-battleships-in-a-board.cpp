class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<int>> &vis){
        int n = board.size(), m = board[0].size();
        if(i>=n || i<0 || j>=m || j<0) return;
        if(board[i][j] == '.') return;
        
        if(vis[i][j] == 1) return;

        vis[i][j] = 1;

        // vertically
        dfs(i+1, j, board, vis);

        // horizontally
        dfs(i, j+1, board, vis);
    }
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] == 0 && board[i][j] == 'X'){
                    ans++;
                    dfs(i, j, board, vis);
                }
            }
        }

        return ans;
    }
};
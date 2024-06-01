class Solution {
public:
    bool valid(int row, int col, vector<string> board){
        int r = row;
        int c = col;

        // uopper diag diagonal
        while(row >=0 && col >=0){
            if(board[row][col] == 'Q') return false;
            row--; col--;
        }
        row = r;
        col = c;

        // check row
        while(col>=0){
            if(board[row][col] == 'Q') return false;
            col--;
        }

        row = r;
        col = c;

        // lower diag
        while(row<board.size() && col >=0){
            if(board[row][col] == 'Q') return false;
            row++; col--;
        }

        return true;

    }
    void solve(int col, vector<string> board, vector<vector<string>>& ans, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row = 0; row<n; row++){
            if(valid(row, col, board)){
                board[row][col] = 'Q';
                solve(col+1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s(n, '.');
        vector<string> board(n);
        for(int i=0; i<n; i++) {
            board[i] = s;
        }
        vector<vector<string>> ans;
        solve(0, board, ans, n);

        return ans;
    }
};
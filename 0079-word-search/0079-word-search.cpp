class Solution {
public: 

    bool bt(vector<vector<char>>& board, string word, int i, int j, int k){
        if(k == word.size()) return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j] == '#') return  false;
        if(board[i][j] != word[k]) return false;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};

        char temp = board[i][j];
        board[i][j] = '#';

        for(int x=0; x<4; x++){
            int nr = i + drow[x];
            int nc = j + dcol[x];

            if(bt(board, word, nr, nc, k+1)) return true;
        }

        board[i][j] = temp;

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == word[0] && bt(board, word, i, j, 0)) return true;
            } 
        }
        return false;
    }
};
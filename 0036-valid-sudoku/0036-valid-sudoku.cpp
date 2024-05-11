class Solution {
public:
    bool validateBox(int sr, int er, int sc, int ec, vector<vector<char>>& board){
        unordered_map<char, bool> mp;
        for(int i=sr; i<=er; i++){
            for(int j=sc; j<=ec; j++){
                if(board[i][j] == '.') continue;
                if(mp.find(board[i][j]) != mp.end()) return false;
                mp[board[i][j]] = 1;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        // validate row
        for(int i=0; i<9; i++){
            unordered_map<char, bool> mp;
            for(int j=0; j<9; j++){
                if(board[i][j] == '.') continue;
                if(mp.find(board[i][j]) != mp.end()) return false;
                mp[board[i][j]] = 1;
            }
        }

        // validate col
        for(int j=0; j<9; j++){
            unordered_map<char, bool> mp;
            for(int i=0; i<9; i++){
                if(board[i][j] == '.') continue;
                if(mp.find(board[i][j]) != mp.end()) return false;
                mp[board[i][j]] = 1;
            }
        }

        for(int sr = 0; sr < 9; sr += 3){
            int er = sr+2;

            for(int sc = 0; sc<9; sc+=3){
                int ec = sc+2;

                if(!validateBox(sr, er, sc, ec, board)) return false; 
            }
        }

        return true;
    }

    // bool isValidSudoku(vector<vector<char>>& board) {
    //     unordered_set<string> st;
        
    //     for(int i = 0; i<9; i++) {
    //         for(int j = 0; j<9; j++) {
    //             if(board[i][j] == '.') continue;
                
    //             string row = string(1, board[i][j]) + "_row_" + to_string(i);
    //             string col = string(1, board[i][j]) + "_col_" + to_string(j);
    //             string box = string(1, board[i][j]) + "_box_" + to_string(i/3) + "_" + to_string(j/3);
    //             if(st.count(row) || st.count(col) || st.count(box)) return false;
    //             st.insert(row);
    //             st.insert(col);
    //             st.insert(box);
    //         }
    //     }
        
    //     return true;
    }
};
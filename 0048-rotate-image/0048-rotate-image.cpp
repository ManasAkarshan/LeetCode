class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // int n = matrix.size();
        // vector<vector<int>> ans(n, vector<int>(n));

        // int k = 0;
        // for(int i=0; i<n; i++){
        //     for(int j=n-1; j>=0; j--){
        //         ans[i][k] = matrix[j][i];
        //         k++;
        //     }
        //     k = 0;
        // }

        // matrix = ans;
        
        reverse(matrix.begin() , matrix.end());
        int row = matrix.size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j <= i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
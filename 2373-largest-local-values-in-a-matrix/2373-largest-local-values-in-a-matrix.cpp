class Solution {
public:
    int findMaxAround(int x, int y, vector<vector<int>>& grid){
        int ans = grid[x][y];
        int n = grid.size();

        for(int i=-1; i<=1; i++){
            for(int j=-1; j<=1; j++){
                int nr = x + i;
                int nc = y + j;

                if(nr<n && nr>=0 && nc<n && nc>=0){
                    ans = max(ans, grid[nr][nc]);
                }
            }
        }

        return ans;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>  ans;
        int m = n-2;

        for(int i=0; i<m; i++){
            vector<int> arr;
            for(int j=0; j<m; j++){
                int temp = findMaxAround(i+1, j+1, grid);
                arr.push_back(temp);
            }
            ans.push_back(arr);
        }

        return ans;
    }
};
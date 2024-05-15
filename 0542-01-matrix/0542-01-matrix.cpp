class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0)), ans(m, vector<int>(n, -1)); 
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j] == 0){
                    ans[i][j] = 0;
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0 ,1, 0, -1};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int s = q.front().second;
            cout<<s<<" sdf"<<endl;
            q.pop();

            for(int i=0; i<4; i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && !visited[nr][nc]){
                    q.push({{nr, nc}, s+1});
                    cout<<s<<endl;
                    ans[nr][nc] = s+1;
                    visited[nr][nc] = 1;
                }
            }
        }
        return ans;
    }
};
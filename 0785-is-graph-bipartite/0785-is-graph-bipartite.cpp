class Solution {
public:
    bool helper(int start, vector<vector<int>>& graph, vector<int> &color){
        int m = graph.size();
        queue<int> q;
        q.push(start);
        color[0] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : graph[node]){
                if(color[it] == -1){
                    color[it] = !color[node];
                    q.push(it);
                }
                else if(color[it] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        // here graph is basically adj list

        int m = graph.size();
        vector<int> color(m, -1);

        // Checking for all multiple components
        for(int i=0; i<m; i++){
            if(color[i] == -1){
                if(!helper(i, graph, color)) return false;
            }
        }
        return true;
    }
};
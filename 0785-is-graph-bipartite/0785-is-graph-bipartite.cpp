class Solution {
public: 
    bool bfs(vector<vector<int>>& graph, int node, vector<int>& color){
        int m = graph.size();

        queue<int> q;
        q.push(node);
        color[node] = 0;

        while(!q.empty()){
            int node  = q.front();
            q.pop();

            for(auto it : graph[node]){
                if(color[it] == -1){
                    q.push(it);
                    color[it] = !color[node];
                }
                else if(color[it] == color[node]) return false;
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int m = graph.size();
        vector<int> color(m,-1);

        for(int i=0; i<m; i++){
            if(color[i] == -1) {
                if(bfs(graph, i, color) == false) return false;
            }
        }

        return true;
    }
};
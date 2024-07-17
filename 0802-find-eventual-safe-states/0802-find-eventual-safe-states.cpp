class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int m = graph.size();
        vector<int> adj[m];
        vector<int> indegree(m, 0);
        for(int i=0; i<m; i++){
            for(auto j : graph[i]){
                adj[j].push_back(i);
                indegree[i]++; 
            }
        }

        // Reverse adj list to find out degree
        // for(int i=0; i<m; i++){
        //     // From i --> it  to  it --> i
        //     for(auto it : adj[i]){
        //         adjRev[it].push_back(i);    // it --> i
        //                      // Basically outdergree of it if it would not have been reveresed
        //     } 
        // }

        queue<int> q;
        vector<int> ans = {};
        for(int i=0; i<m; i++){
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int top = q.front();
            q.pop();
            ans.push_back(top);

            for(auto adjNode : adj[top]){
                indegree[adjNode]--;
                if(indegree[adjNode] == 0) 
                    q.push(adjNode);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
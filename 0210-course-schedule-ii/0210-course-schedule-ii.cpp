class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];

        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        queue<int> q;
        vector<int> in(numCourses, 0);
        vector<int> ans;

        for(int i=0; i<numCourses; i++){
            for(auto it : adj[i]) in[it]++;
        }

        for(int i=0; i<in.size(); i++) if(in[i] == 0) q.push(i);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it : adj[node]){
                in[it]--;
                if(in[it] == 0) q.push(it);
            }
        }
        reverse(ans.begin(), ans.end());
        if(ans.size() == numCourses) return ans;
        
        return {};
    }
};
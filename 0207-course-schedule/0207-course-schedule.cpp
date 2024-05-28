class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];

        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        queue<int> q;
        int cnt = 0;
        vector<int> indegree(numCourses, 0);

        for(int i=0; i<numCourses; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        for(int i=0; i<indegree.size(); i++){
            cout<<indegree[i]<<" ";
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;

            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        cout<<cnt;
        return cnt == numCourses;
    }
};
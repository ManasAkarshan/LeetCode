class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adjList[numCourses];

        for(auto it : prerequisites){
            adjList[it[0]].push_back(it[1]);
        }

        int cnt = 0;
        queue<int> q;
        vector<int> indegree(numCourses, 0);

        for(int i=0; i<numCourses; i++){
            for(auto it:adjList[i]){
                indegree[it]++;
            }
        }

        for(int i=0;i<indegree.size(); i++){
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;

            for(auto it : adjList[node]){
                indegree[it]--;
                cout<<indegree[it];
                if(indegree[it] == 0) q.push(it);
            }
        }
        cout<<cnt;
        return cnt == numCourses;
    }
};
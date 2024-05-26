class Solution {
public:
    void solve(int node, vector<vector<int>>& graph, vector<int> temp, vector<vector<int>>& ans, int target){
        if(node == target){
            ans.push_back(temp);
            return;
        }

        for(auto it : graph[node]){
            temp.push_back(it);
            solve(it, graph, temp, ans, target);
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int m = graph.size();
        solve(0, graph, {0}, ans, m-1);

        return ans;
    }
};
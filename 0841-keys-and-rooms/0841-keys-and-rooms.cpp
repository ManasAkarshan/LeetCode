class Solution {
public:
    void dfs(int ind, vector<vector<int>>& rooms, vector<int>& vis){
        vis[ind] = 1;    // 0

        auto keys = rooms[ind];    // rooms[0] -> [1]
        if(keys.size() == 0) return;

        for(auto i : keys){
            if(!vis[i]) dfs(i, rooms, vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<int> vis(n, 0);

        dfs(0, rooms, vis);

        for(int i=0; i<n; i++){
            if(vis[i] == 0) return false;
        }

        return true;
    }
};
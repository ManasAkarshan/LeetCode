class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {

        int n = source.size();
        vector<vector<int>> dist(26, vector<int>(26, 1e8));

        for (int i = 0; i < changed.size(); i++) {
            int old = original[i] - 'a';
            int ch = changed[i] - 'a';
            dist[old][ch] = min(dist[old][ch], cost[i]);
        }

        for (int i = 0; i < 26; i++)
            dist[i][i] = 0;

        for (int via = 0; via < 26; via++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int org = (int)source[i] - 'a';
            int nw = (int)target[i] - 'a';
            if(dist[org][nw] == 1e8) return -1;
            ans += dist[org][nw];
        }

        return ans>=1e8 ? -1 : ans;
    }
};
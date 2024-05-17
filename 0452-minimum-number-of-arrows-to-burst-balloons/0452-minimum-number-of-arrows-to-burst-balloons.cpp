class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int i=1, cnt = 1, n = points.size();
        sort(points.begin(), points.end(), comp);
        vector<int> prev = points[0];
        cout<<prev[1];

        while(i<n){
            if(prev[1] >= points[i][0]){
                i++;
            }

            else{
                prev = points[i];
                i++;
                cnt++;
            }
        }

        return cnt;
    }
};
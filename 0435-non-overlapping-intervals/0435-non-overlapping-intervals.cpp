class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size(),cnt = 0;
        sort(intervals.begin(), intervals.end());
        
        vector<int> LastIntv = intervals[0];
        for(int i=1; i<n; i++){ 
            int curr_start = intervals[i][0];
            int curr_end = intervals[i][1];
            
            int last_end = LastIntv[1];

            if(last_end <= curr_start){
                LastIntv = intervals[i];
            }
            else if(last_end <= curr_end){
                cnt++;
            }
            else if(last_end > curr_end){
                LastIntv = intervals[i];
                cnt++;
            }
        }

        return cnt;
    }
};
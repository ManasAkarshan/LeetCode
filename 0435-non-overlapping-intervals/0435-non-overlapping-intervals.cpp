class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> temp;

        for(int i=0; i<intervals.size(); i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(temp.empty()) temp.push_back({start, end});

            else{
                if(start>=temp.back()[1]){
                    temp.push_back({start, end});
                }
            }
        }

        return intervals.size()-temp.size();
    }
};
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0, j=height.size()-1;
        int ans = 0, water;

        while(i<j){
            int h = min(height[i], height[j]);
            water = (j-i)*h;
            ans = max(ans, water);
            if(height[i] <= h && i<j) i++;
            if(height[j] <= h && j>i) j--;
        }
        return ans;
    }
};
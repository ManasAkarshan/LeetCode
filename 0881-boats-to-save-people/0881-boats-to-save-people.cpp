class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i=0, ans=0, j=people.size()-1;

        while(i<=j){
            if(people[i] + people[j] <= limit) {
                ans += 1; 
                i++; j--;
            }
            else{
                j--;
                ans += 1;
            }
        }

        return ans;
    }
};
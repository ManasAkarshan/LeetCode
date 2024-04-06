class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;

        for(int i=0; i<gas.size(); i++){
            totalGas += gas[i];
            totalCost += cost[i];
        }
        int total = 0, start = 0;
        if(totalGas<totalCost) return -1;

        for(int i=0; i<gas.size(); i++){
            total = gas[i]-cost[i];
            if(total<0){
                total = 0;
                start = i+1;
            }
        }
        return start;
    }
};
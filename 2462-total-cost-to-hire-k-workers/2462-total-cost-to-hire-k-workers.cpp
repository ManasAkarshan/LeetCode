// class Solution {
// public:
//     long long totalCost(vector<int>& costs, int k, int candidates) {
        
//         long long cost = 0;

//         while(k>0){
//             priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//             if(2*candidates < costs.size()){
//                 for(int i=costs.size()-candidates; i<costs.size(); i++){
//                     pq.push({costs[i], i});
//                 }
//                 for(int i=0; i<candidates; i++){
//                     pq.push({costs[i], i});
//                 }
//                 pair<int,int> temp = pq.top();
//                 pq.pop();
//                 cost += temp.first;
//                 costs.erase(costs.begin()+temp.second);
//                 k--;
//             }
//             else{
//                 break;
//             }
//         }

//         priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//         for(int i=0; i<costs.size(); i++){
//             pq.push({costs[i], i});
//         }

//         while(k>0 && !pq.empty()){
//             cost += pq.top().first;
//             pq.pop();
//             k--;
//         }
//         return cost;
//     }
// };

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates)
    {
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;

        long long cost = 0;   
 
        int count = 0;
        int low = 0;
        int high = costs.size()-1;

        while(count < k)
        {
            while( (pq1.size() < candidates) && (low <= high) )
            {
                pq1.push(costs[low]);
                low += 1;
            }

            while( (pq2.size() < candidates) && (high >= low) )
            {
                pq2.push(costs[high]);
                high -= 1;
            }

            int cost1 = (pq1.size() > 0) ? pq1.top() : INT_MAX;
            int cost2 = (pq2.size() > 0) ? pq2.top() : INT_MAX;

            if(cost1 <= cost2)
            {
                cost += cost1;
                pq1.pop();
            }
            else
            {
                cost += cost2;
                pq2.pop();
            }

            count += 1;
        }

        return cost;
    }
};
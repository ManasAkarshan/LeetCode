class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        
        vector<int> res(n, 0);
        queue<int> q;
        for (int i = 0; i < n; i++)
            q.push(i);

        int i=0;
        while(!q.empty()) {
            int u = q.front();     // maan lo 0
            q.pop();

            res[u] = deck[i++];

            if (!q.empty()) {    // 0 le liye to 1 pop and wapis peeche se daal diye
                q.push(q.front());
                q.pop();
            }
        }

        return res;
    }
};
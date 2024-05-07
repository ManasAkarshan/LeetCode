class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    SmallestInfiniteSet() {
        for(int i=1; i<=1000; i++) pq.push(i);
    }
    
    int popSmallest() {
        if(!pq.empty()){
            int top = pq.top();
            pq.pop();
            return top;
        }
        return -1;
    }
    
    void addBack(int num) {
        vector<int> temp;
        while(!pq.empty()){
            if(pq.top() == num) break;
            else if(pq.top() > num) {
                pq.push(num); break;
            }
            else{
                temp.push_back(pq.top());
                pq.pop();
            }
        }

        for(int i=temp.size()-1; i>=0; i--) pq.push(temp[i]);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
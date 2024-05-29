class cmp {
public:
	bool operator()(pair<int, int> A, pair<int, int> B) {
		if (A.first < B.first) {
			return true;
		}
		if (A.first > B.first) {
			return false;
		}
		if (A.first == B.first) {
			return A.second > B.second;
		}

        return true;
	}
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;

        int i=0, j=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

        while(i<nums.size()){
            pq.push({nums[i], i});

            if(i-j+1 == k){
                while(pq.top().second<j) pq.pop();

                ans.push_back(pq.top().first);
                if(nums[j] == pq.top().first) pq.pop();
                j++;
            }
            i++;
        }

        return ans;
    }
};
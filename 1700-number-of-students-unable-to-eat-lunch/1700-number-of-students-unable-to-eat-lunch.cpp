class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size(), cnt = 0;
        stack<int> st;
        queue<int> q;
        for(int i=0; i<n; i++){
            q.push(students[i]);
            st.push(sandwiches[n-i-1]);
        }
        while(!q.empty() && !st.empty()){
            if(q.front() == st.top()){
                q.pop(); st.pop();
                cnt = 0;
            }
            else{
                int temp = q.front(); 
                q.pop();
                q.push(temp);
                cnt += 1;
                if(cnt == q.size()) return q.size();
            }
        }
        return 0;
    }
};
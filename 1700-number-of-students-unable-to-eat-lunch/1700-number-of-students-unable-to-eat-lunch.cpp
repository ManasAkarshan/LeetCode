class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size(), cnt = 0;
        int st0 = 0, st1 = 0;
        // queue<int> q;
        // for(int i=0; i<n; i++){
        //     q.push(students[i]);
        //     st.push(sandwiches[n-i-1]);
        // }
        // while(!q.empty() && !st.empty()){
        //     if(q.front() == st.top()){
        //         q.pop(); st.pop();
        //         cnt = 0;
        //     }
        //     else{
        //         int temp = q.front(); 
        //         q.pop();
        //         q.push(temp);
        //         cnt += 1;
        //         if(cnt == q.size()) return q.size();
        //     }
        // }
        // return 0;

        for(int i=0; i<n; i++) students[i]==0 ? st0++ : st1++;

        for(int i=0; i<n; i++){
            if(sandwiches[i] == 1){
                if(st1 == 0) return n-i;
                st1--;
            }
            else{
                if(st0 == 0) return n-i;
                st0--;
            }
        }
        return 0;
    }
};
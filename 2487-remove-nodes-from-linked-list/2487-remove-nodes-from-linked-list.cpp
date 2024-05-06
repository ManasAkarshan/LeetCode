/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        vector<int> st;
        ListNode* temp = head, *dummy = new ListNode(-1), *ans = dummy;

        while(temp){
            while(!st.empty() && st.back()<temp->val){
                st.pop_back();
            }
            st.push_back(temp->val);
            temp = temp->next;
        }

        for(int i=0; i<st.size(); i++){
            ListNode* nn = new ListNode(st[i]);
            dummy->next = nn;
            dummy = dummy->next;
        }

        return ans->next;
    }
};
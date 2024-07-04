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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head->next, *dummy = new ListNode(-1), *ans = dummy;
        int sum = 0;

        while(temp){
            if(temp->val == 0){
                ListNode* nn = new ListNode(sum);
                dummy->next = nn;
                dummy = dummy->next;
                sum = 0;
            }
            else{
                sum += temp->val;
            }

            temp = temp->next;
        }

        return ans->next;
    }
};
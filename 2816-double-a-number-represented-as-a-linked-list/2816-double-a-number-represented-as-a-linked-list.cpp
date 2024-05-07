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
    ListNode* reverse(ListNode* head){
        if(!head) return NULL;

        ListNode* prev = NULL, *curr = head, *nxt = NULL;

        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* temp = reverse(head), *dummy = new ListNode(-1), *ans = dummy;

        int carry = 0;

        while(temp){
            int sum = carry + temp->val + temp->val;
            carry = sum/10;
            sum = sum%10;

            ListNode* nn = new ListNode(sum);
            dummy->next = nn;
            dummy = dummy->next;
            temp = temp->next;
        }

        if(carry){
            ListNode* nn = new ListNode(carry);
            dummy->next = nn;
            dummy = dummy->next;
        }

        return reverse(ans->next);
    }
};
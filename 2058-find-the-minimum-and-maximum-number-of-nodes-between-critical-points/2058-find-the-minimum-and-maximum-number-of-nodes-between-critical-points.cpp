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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int firstOcc=-1, lastOcc=-1, minDist = INT_MAX, maxDist = INT_MIN;
        int i=2, prevVal = head->val, nextVal;
        ListNode* temp = head->next;

        while(temp->next){
            if((temp->val > prevVal && temp->val>temp->next->val) || (temp->val < prevVal && temp->val<temp->next->val)){
                if(firstOcc == -1) firstOcc = i;
                if(lastOcc != -1) {
                    minDist = min(minDist, (i-lastOcc));
                    maxDist = max((lastOcc-firstOcc), maxDist);
                }
                lastOcc = i;
            }
            prevVal = temp->val;
            i++;
            temp = temp->next;
        }
        if(minDist == INT_MAX && maxDist == INT_MIN) return {-1, -1};

        if(lastOcc != -1) maxDist = max((lastOcc-firstOcc), maxDist);

        return {minDist, maxDist};
    }
};
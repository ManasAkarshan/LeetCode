class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class Solution {
public:
    int findTheWinner(int n, int k) {
        Node* head = new Node(1), *temp = head;
        for(int i=2; i<=n; i++){
            temp->next = new Node(i);
            temp = temp->next;
        }

        temp->next = head;
        cout<<temp->data;

        int t = k;
        while(true){
            if(head->next == head) return head->data;
            while(t > 1){
                head = head->next;
                temp = temp->next;
                t--;
            }
            temp->next = head->next;
            head->next = NULL;
            head = temp->next;
            t = k;
        }
        return -1;
    }
};
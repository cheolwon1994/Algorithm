class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int len = 0;
        while(temp!=nullptr){
            len++;
            temp = temp->next;
        }
        if(n == len) return head->next;

        len -= (n+1);
        temp = head;
        while(len-- > 0){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};

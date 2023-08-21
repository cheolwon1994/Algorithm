class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* rightNode;
        ListNode* rightRightNode;
        ListNode* answer = new ListNode(0);
        ListNode* temp = answer;
        
        while(head !=nullptr){
            if(head->next == nullptr){
                temp->next = new ListNode(head->val);
                head = head->next;
                temp = temp->next;
            }
            else{
                temp->next = new ListNode(head->next->val);
                temp = temp->next;
                temp->next = new ListNode(head->val);
                head = head->next->next;
                temp = temp->next;
            }
        }  

        return answer->next;
    }
};

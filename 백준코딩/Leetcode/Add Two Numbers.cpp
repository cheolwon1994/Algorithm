class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root = new ListNode();
        ListNode* head = root;
        int carry = 0;
        while(l1!=nullptr || l2!=nullptr || carry!=0){
            int a = l1!=nullptr ? l1->val : 0;
            int b = l2!=nullptr ? l2->val : 0;
            int sum = a+b+carry;
            carry = sum/10;
            ListNode* node = new ListNode(sum%10);
            if(l1!=nullptr) l1 = l1->next;
            if(l2!=nullptr) l2 = l2->next;
            head->next = node;
            head = head->next;
        }
        return root->next;
    }
};

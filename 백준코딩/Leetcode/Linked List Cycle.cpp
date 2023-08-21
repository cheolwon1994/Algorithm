class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        ListNode *slow = head;
        ListNode *fast = head;

        while(slow->next != nullptr && fast->next!=nullptr){
            slow = slow->next;
            if(fast->next->next == nullptr) return false;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};

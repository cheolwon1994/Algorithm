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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* root = new ListNode();
        ListNode* head = root;
        while(list1!=nullptr && list2!=nullptr){
            int val1 = list1->val;
            int val2 = list2->val;
            //add list1's val
            if(val1<val2){
                ListNode* node = new ListNode(val1);
                head->next = node;
                head = head->next;
                list1=list1->next;
            }
            else{
                ListNode* node = new ListNode(val2);
                head->next = node;
                head = head->next;
                list2=list2->next;
            }
        }

        while(list1!=nullptr){
            ListNode* node = new ListNode(list1->val);
            head->next = node;
            head = head->next;
            list1=list1->next;
        }

        while(list2!=nullptr){
            ListNode* node = new ListNode(list2->val);
            head->next = node;
            head = head->next;
            list2=list2->next;
        }

        return root->next;
    }
};

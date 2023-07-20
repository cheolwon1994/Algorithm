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
    void reorderList(ListNode* head) {
        ListNode* node = head;
        stack<ListNode*> s;
        int len = 0;
        while(node!=nullptr){
            s.push(node);
            node = node->next;
            len++;
        }
        node = head;
        int cnt = 0;
        ListNode* saveNextNode;
        while(cnt<len){
            //same
            //save nextNode for original nodeList
            if(node->next!=nullptr) saveNextNode = node->next;
            cnt++;
            //move to next
            if(cnt==len) break;

            node->next = s.top();
            s.pop();
            //change
            node = node->next;
            node->next = saveNextNode;
            cnt++;
            node = node->next;
        }
        //set node's next to nullptr
        node->next = nullptr;
    }
};

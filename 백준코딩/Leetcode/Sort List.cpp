lass Solution {
    struct info {
        int val;
        ListNode* node;
    };
    struct cmp{
        bool operator()(info &a, info &b){
            return a.val > b.val;
        }
    };

public:
    ListNode* sortList(ListNode* head) {
        priority_queue<info, vector<info>, cmp> pq;

        while(head != nullptr){
            pq.push({head->val, head});
            head = head->next;
        }

        ListNode* root = new ListNode();
        ListNode* temp = root;
        while(!pq.empty()){
            info ii = pq.top();
            pq.pop();
            temp->next = ii.node;
            temp = temp->next;
        }
        temp->next = nullptr;

        return root->next;
    }
};

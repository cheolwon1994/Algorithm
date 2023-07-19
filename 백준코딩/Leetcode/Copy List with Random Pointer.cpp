/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* root = new Node(0);
        Node* headDup = head;
        Node* rootDup = root;
        Node* answer = root;
        map<Node*,Node*> headToRoot;
        
        while(head!=nullptr){
            Node* node = new Node(head->val);
            headToRoot[head] = node;
            root->next = node;
            head = head->next;
            root = root->next;
        }

        rootDup = rootDup->next;
        while(headDup!=nullptr){
            if(headDup->random!=nullptr){
                Node* matchedNode = headToRoot[headDup->random];
                rootDup->random = matchedNode;
            }
            headDup = headDup->next;
            rootDup = rootDup->next;
        }

        return answer->next;
    }
};

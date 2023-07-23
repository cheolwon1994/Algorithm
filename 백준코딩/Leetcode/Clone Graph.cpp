/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        map<Node*,Node*> originToDupMap;
        map<Node*,vector<Node*>> dupOriginNeighborMap;
        Node* root = nullptr;
        queue<Node*> q;
        // Node* start = new Node(node->val);
        q.push(node);
        set<Node*> s;
        s.insert(node);

        while(!q.empty()){
            Node* topNode = q.front();
            q.pop();
            Node* newNode = new Node(topNode->val);
            if(root==nullptr) root = newNode;
            //insert to originToDupMap
            originToDupMap[topNode] = newNode;

            vector<Node*> next = topNode->neighbors;
            for(int i=0;i<next.size();i++){
                dupOriginNeighborMap[newNode].push_back(next[i]);
                if(s.find(next[i])==s.end()){
                    q.push(next[i]);
                    s.insert(next[i]);
                }
            }
        }

        for(auto it = dupOriginNeighborMap.begin();it!=dupOriginNeighborMap.end();it++){
            Node* dup = it->first;
            vector<Node*> dupsNeighbor = it->second;
            for(int i=0;i<dupsNeighbor.size();i++){
                dupsNeighbor[i] = originToDupMap[dupsNeighbor[i]];
            }
            dup->neighbors = dupsNeighbor;
        }

        return root;
    }
};

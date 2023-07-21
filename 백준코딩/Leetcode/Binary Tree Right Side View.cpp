/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    struct info{
        int height;
        TreeNode* node;
    };
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<info> q;
        vector<int> answer;

        if(root==nullptr) return answer;
        int curHeight = 0;
        q.push({1,root});
        while(!q.empty()){
            info ii = q.front();
            q.pop();
            int cheight = ii.height;
            TreeNode* node = ii.node;
            if(cheight>curHeight){
                curHeight = cheight;
                answer.push_back(node->val);
            }
            if(node->right!=nullptr){
                q.push({cheight+1,node->right});
            }
            if(node->left!=nullptr){
                q.push({cheight+1,node->left});
            }
        }
        
        return answer;
    }
};

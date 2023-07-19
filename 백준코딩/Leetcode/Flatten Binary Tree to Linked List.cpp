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
public:
    TreeNode* getPreorder(TreeNode* node){
        if(node==nullptr) return node;
        TreeNode* head = node;
        TreeNode* right = node->right;
        node->right = nullptr;
        
        if(node->left!=nullptr){
            node->right = getPreorder(node->left);
            node->left = nullptr;
        }
        if(right!=nullptr){
            //set head to the rightest node
            while(node->right!=nullptr){
                node = node->right;
            }
            node->right = getPreorder(right);
        }
        return head;
    }

    void flatten(TreeNode* root) {
        root = getPreorder(root);
    }
};

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
    bool isBST(TreeNode* node, long long mini, long long maxi){
        int val = node->val;
        if(val<=mini || val>=maxi) return false;
        bool avail = true;
        if(node->left!=nullptr){
            avail&=isBST(node->left,mini,val);
        }
        if(node->right!=nullptr){
            avail&=isBST(node->right,val,maxi);
        }
        return avail;
    }

    bool isValidBST(TreeNode* root) {
        long long mini = LLONG_MIN;
        long long maxi = LLONG_MAX;
        int val = root->val;
        bool avail = true;
        if(root->left!=nullptr) avail&=isBST(root->left,mini,val);
        if(root->right!=nullptr) avail&=isBST(root->right,val,maxi);

        return avail;
    }
};

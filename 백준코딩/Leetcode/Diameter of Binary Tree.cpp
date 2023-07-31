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
    int maxLen;
    int dfs(TreeNode* node){
        if(node==nullptr) return 0;
        if(node->left==NULL && node->right==NULL) return 0;
        int leftChild = node->left==NULL ? 0 : dfs(node->left)+1;
        int rightChild = node->right==NULL ? 0 : dfs(node->right)+1;
        maxLen = max(maxLen,leftChild+rightChild);
        return max(leftChild,rightChild);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        maxLen = 0;
        dfs(root);
        return maxLen;
    }
};

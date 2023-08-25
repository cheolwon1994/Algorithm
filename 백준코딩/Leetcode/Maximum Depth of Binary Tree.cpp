class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int childHeight = 0;
        childHeight = max(maxDepth(root->left), maxDepth(root->right));
        return childHeight + 1;
    }
};

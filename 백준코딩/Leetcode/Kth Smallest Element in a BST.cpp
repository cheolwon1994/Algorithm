class Solution {
public:
    int cnt, answer;

    void dfs(TreeNode* node, int k){
        if(node->left != nullptr) dfs(node->left, k);
        if(++cnt == k) answer = node->val;
        if(node->right != nullptr) dfs(node->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        cnt = 0;
        dfs(root,k);
        return answer;
    }
};

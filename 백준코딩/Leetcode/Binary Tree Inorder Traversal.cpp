class Solution {
public:
    void inorder(TreeNode* node, vector<int> &answer){
        if(node == nullptr) return;
        if(node->left != nullptr) inorder(node->left, answer);
        answer.push_back(node->val);
        if(node->right != nullptr) inorder(node->right, answer);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        inorder(root, answer);

        return answer;
    }
};

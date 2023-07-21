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
class BSTIterator {
    vector<int> v;
    int idx = 0;
    int len = 0;
public:

    BSTIterator(TreeNode* root) {
        getInorder(root);
    }
    
    int next() {
        return v[idx++];
    }
    
    bool hasNext() {
        return idx<len;
    }

    void getInorder(TreeNode* root){
        if(root->left != nullptr) getInorder(root->left);
        v.push_back(root->val);
        len++;
        if(root->right!=nullptr) getInorder(root->right);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

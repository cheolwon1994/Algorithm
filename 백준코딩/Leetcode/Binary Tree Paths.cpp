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
        string path;
        TreeNode* node;
    };

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root == nullptr) return ans;
        queue<info> q;
        q.push({"",root});
        while(!q.empty()){
            info ii = q.front();
            q.pop();
            string path = ii.path;
            TreeNode* node = ii.node;
            int val = node->val;
            if(path == "") path = to_string(val);
            else path+=("->"+to_string(val));
            bool isLeaf = (node->left == nullptr) && (node->right == nullptr);
            if(isLeaf){
                ans.push_back(path);
                continue;
            }
            if(node->left!=nullptr) q.push({path,node->left});
            if(node->right!=nullptr) q.push({path,node->right});
        }
        return ans;
    }
};

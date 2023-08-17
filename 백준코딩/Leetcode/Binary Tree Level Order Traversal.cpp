class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        if(root == nullptr) return answer;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int len = q.size();
            vector<int> temp;
            for(int k=0;k<len;k++){
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
            }
            answer.push_back(temp);
        }

        return answer;
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr) return true;

        queue<TreeNode*> q;
        int nullNum = 101;

        if(root->left != nullptr && root->right != nullptr){
            if(root->left->val != root->right->val) return false;
            q.push(root->left);
            q.push(root->right);
            vector<int> v;

            while(!q.empty()){
                int len = q.size();
                v.clear();
                for(int k=0;k<len;k++){
                    TreeNode* node = q.front();
                    q.pop();
                    int val;
                    //left
                    if(node->left != nullptr){
                        q.push(node->left);
                        val = node->left->val;
                    }
                    else val = nullNum;
                    v.push_back(val);

                    //right
                    if(node->right != nullptr){
                        q.push(node->right);
                        val = node->right->val;
                    }
                    else val = nullNum;
                    v.push_back(val);
                }

                int vlen = v.size();
                if(vlen % 2 == 1) return false;
                for(int i=0;i<vlen/2;i++){
                    if(v[i] != v[vlen-1-i])
                        return false;
                }
            }
            return true;
        }
        else return false;
    }
};

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*>q;
        q.push(root);
        bool past = false;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(node==NULL){
                past = true;
            }
            else {
                if(past) return false;
                else{
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }
        return true;
    }
};
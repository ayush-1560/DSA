class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* curr = root;
        while(curr){
            if(!curr->left){
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* leftchild=curr->left;
                while(leftchild->right){
                    leftchild=leftchild->right;
                }
                leftchild->right=curr;
                TreeNode* temp = curr;
                curr=curr->left;
                temp->left=NULL;
            }
        }
        return ans;
    }
};
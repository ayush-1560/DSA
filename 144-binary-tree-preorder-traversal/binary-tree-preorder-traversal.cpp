class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode*>st;
        st.push(root);
        vector<int>ans;
        while(!st.empty()){
            TreeNode* root = st.top();
            st.pop();
            ans.push_back(root->val);
            if(root->right) st.push(root->right);
            if(root->left) st.push(root->left);
        }
        return ans;
    }
};
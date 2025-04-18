class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
       if(!root) return {};
       stack<TreeNode*>st;
       vector<int>ans;
       TreeNode* curr = root;
       while(curr || !st.empty()){
           while(curr){
            st.push(curr);
            curr=curr->left;
           }
           curr = st.top();
           st.pop();
           ans.push_back(curr->val);
           curr=curr->right;
       }
       return ans;
    }
};
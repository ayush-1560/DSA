class Solution {
public:
    int totalsum=0;
    void solve(TreeNode* root,string s){
        if(!root) return;
        s+=to_string(root->val);
        if(!root->left && !root->right){
            totalsum+=stoi(s);
            return;
        }
        else{
            solve(root->left,s);
            solve(root->right,s);
        }
        s.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        solve(root,"");
        return totalsum;
    }
};
class Solution {
public:
    void helper(TreeNode* root,string temp,vector<string>&ans){
        if(!root) return;
        if(!root->left && !root->right) {
            temp+=to_string(root->val);
            ans.push_back(temp);
            return;
        }
        temp+=to_string(root->val)+"->";
        helper(root->left,temp,ans);
        helper(root->right,temp,ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string temp="";
        helper(root,temp,ans);
        return ans;
    }
};
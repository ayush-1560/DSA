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
public:
    bool inorder(TreeNode* root,long long& val){
        if(!root) return true;
        bool l = inorder(root->left,val);
        if(root->val <= val) return false;
        val = root->val;
        bool r=inorder(root->right,val);
        return l && r;
    }
    bool isValidBST(TreeNode* root) {
        long long val = LLONG_MIN;
        return inorder(root,val);
    }
};
class Solution {
public:
    vector<int>ans;
    int currNum=0, currFreq=0;
    int maxFreq=0;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        if(currNum==root->val){
            currFreq++;
        }
        else{
            currFreq=1;
            currNum=root->val;
        }
        if(currFreq>maxFreq){
            maxFreq=currFreq;
            ans={};
        }
        if(currFreq==maxFreq){
            ans.push_back(root->val);
        }
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }
};
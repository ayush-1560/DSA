class Solution {
public:
    unordered_map<int,int>mp;
    int maxFreq=INT_MIN;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        mp[root->val]++;
        maxFreq=max(maxFreq,mp[root->val]);
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        vector<int>ans;
        for(auto it : mp){
            if(it.second==maxFreq) ans.push_back(it.first);
        }
        return ans;
    }
};
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& v){
        if(!root) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2, ans;
        inorder(root1, v1);
        inorder(root2, v2);
        int i = 0, j = 0;
        while(i < v1.size() && j < v2.size()){
            if(v1[i]<=v2[j]){
                ans.push_back(v1[i]);
                i++;
            }
            else{
                ans.push_back(v2[j]);
                j++;
            }
        }
        while(i<v1.size()){
            ans.push_back(v1[i]);
            i++;
        }
        while(j<v2.size()){
            ans.push_back(v2[j]);
            j++;
        }
        return ans;
    }
};
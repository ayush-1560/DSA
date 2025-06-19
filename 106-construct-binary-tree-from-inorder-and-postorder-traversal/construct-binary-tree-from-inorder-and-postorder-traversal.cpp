class Solution {
public:
    int search(vector<int>& inorder,int start,int end,int ele){
        for(int i=start;i<=end;i++){
            if(inorder[i]==ele) return i;
        }
        return -1;
    }
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder,int& postIdx,int start,int end){
        if(start>end) return NULL;
        TreeNode* root= new TreeNode(postorder[postIdx]);
        int inIdx=search(inorder,start,end,postorder[postIdx]);
        postIdx++;
        root->right = helper(inorder,postorder,postIdx,inIdx+1,end);
        root->left =helper(inorder,postorder,postIdx,start,inIdx-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        reverse(postorder.begin(),postorder.end());
        int postIdx=0;
        return helper(inorder,postorder,postIdx,0,inorder.size()-1);
    }
};
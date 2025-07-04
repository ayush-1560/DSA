class Solution {
public:
    void inorder(TreeNode* root,vector<int>&v){
        if(!root) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    int lower(vector<int>&v,int ele){
        int low = 0, high = v.size()-1;
        int ans =-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(v[mid]<=ele){
                ans=v[mid];
                low = mid+1;
            }
            else high = mid-1;
        }
        return ans;
    }
    int higher(vector<int>&v,int ele){
        int low = 0, high = v.size()-1;
        int ans =-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(v[mid]>=ele){
                ans=v[mid];
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int>v;
        vector<vector<int>>ans;
        inorder(root,v);
        for(int query : queries){
            ans.push_back({lower(v,query),higher(v,query)});
        }
        return ans;
    }
};
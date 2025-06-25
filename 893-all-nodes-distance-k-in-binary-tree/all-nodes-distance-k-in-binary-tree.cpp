class Solution {
public:
    void inorder(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&mp){
        if(!root) return;
        inorder(root->left,mp);
        if(root->left)mp[root->left]=root;
        if(root->right)mp[root->right]=root;
        inorder(root->right,mp);
    }
    void BFS(TreeNode* target,int k,vector<int>&ans,unordered_map<TreeNode*,TreeNode*>&mp){
        queue<TreeNode*>q;
        unordered_set<int>vis;
        vis.insert(target->val);
        q.push(target);
        while(!q.empty()){
            int n = q.size();
            if(k==0) break;
            while(n--){
                auto node = q.front();
                q.pop();
                if(node->left && !vis.count(node->left->val)){
                    q.push(node->left);
                    vis.insert(node->left->val);
                }
                if(node->right && !vis.count(node->right->val)) {
                    q.push(node->right);
                    vis.insert(node->right->val);
                }
                if(mp.count(node) && !vis.count(mp[node]->val)){
                    q.push(mp[node]);
                    vis.insert(mp[node]->val);
                }
            }
            k--;
        }
        while(!q.empty()){
                ans.push_back(q.front()->val);
                q.pop();
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>mp;
        vector<int>ans;
        inorder(root,mp);
        BFS(target,k,ans,mp);
        return ans;
    }
};
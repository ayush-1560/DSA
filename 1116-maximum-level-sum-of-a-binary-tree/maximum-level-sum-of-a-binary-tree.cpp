class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxLevel = 1;
        int level = 0;
        int maxSum = root->val;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            level++;
            int currSum = 0;
            while(n--){
                auto node = q.front();
                q.pop();
                currSum+=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(currSum > maxSum){
                maxLevel = level;
                maxSum = currSum;
            }
        }
        return maxLevel;
    }
};
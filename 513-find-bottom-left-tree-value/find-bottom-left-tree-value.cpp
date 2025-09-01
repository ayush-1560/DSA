class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int leftmost = root->val;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (i == 0) leftmost = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return leftmost;
    }
};
class Box{
    public:
        bool BST;
        int sum;
        int Min;
        int Max;
        Box(){
            BST=true;
            sum=0;
            Min =INT_MAX;
            Max=INT_MIN;
        }
};
class Solution {
public:
Box* find(TreeNode* root,int & maxSum){
    if(!root){
        return new Box();
    }
    Box* leftHead = find(root->left,maxSum);
    Box* rightHead = find(root->right,maxSum);
    if(leftHead->BST && rightHead->BST && leftHead->Max < root->val
    && rightHead->Min > root->val){
        Box* head = new Box ();
        head ->sum = root->val + leftHead->sum + rightHead->sum;
        head->Min = min(root->val, leftHead->Min);
        head->Max = max(root->val, rightHead->Max);
        maxSum = max(maxSum,head->sum);
        return head;
    }
    else {
        leftHead->BST=0;
        return leftHead;
    }
}
    int maxSumBST(TreeNode* root) {
        int maxSum=INT_MIN;
        find(root,maxSum);
        return maxSum<=0 ? 0 : maxSum;
    }
};
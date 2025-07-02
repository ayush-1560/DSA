class Solution {
public:
    TreeNode* makeTree(ListNode* head){
        if(!head) return NULL;
        ListNode* slow = head,*fast = head,* prev=NULL,*Next=NULL;
        while(fast && fast->next){
            prev=slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode * root = new TreeNode(slow->val);
        if(prev){
            prev->next=NULL;
            root->left = makeTree(head);
        }
        root->right = makeTree(slow->next);
        slow->next=NULL;
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return makeTree(head);
    }
};
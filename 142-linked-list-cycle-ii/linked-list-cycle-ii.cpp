
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*>st;
        ListNode* temp = head;
        while(temp){
            if(st.count(temp)) return temp;
            st.insert(temp);
            temp = temp->next;
        }
        return NULL;
    }
};
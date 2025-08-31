class Solution {
public:
    typedef pair<int,ListNode*> p;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        priority_queue<p,vector<p>,greater<p>>pq;
        for(ListNode* list : lists){
            if(list)  pq.push({list->val,list});
        }
        ListNode* dummy = new ListNode(-100);
        ListNode* tempD = dummy;
        while(!pq.empty()){
            ListNode* node = pq.top().second;
            pq.pop();
            tempD->next = node;
            tempD = node;
            if(node->next) pq.push({node->next->val,node->next});
        }
        return dummy->next;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* t1=headA;
        ListNode* t2 =headB;
        int len1=0,len2=0;
        while(t1){
            len1++;
            t1=t1->next;
        }
        while(t2){
            len2++;
            t2=t2->next;
        }
        t1=headA,t2=headB;
        if(len1>len2){
            int len=len1-len2;
            while((len)>0) {
                t1=t1->next;
                (len)--;
            }
        }
        else if(len2>len1){
            int len=len2-len1;
            while(len--) t2=t2->next; 
        }
        ListNode* ans=NULL;
        while(t1 && t2){
            if(t1==t2){
                ans=t1;
                break;
            }
            t1=t1->next;
            t2=t2->next;
        }
        return ans;
    }
};
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
        ListNode *a=headA;
       ListNode *b=headB;
        int count1=0,count2=0;
        while(headA){
            headA=headA->next;
            count1++;
        }
        while(headB){
            headB=headB->next;
            count2++;
        }
        while(count1>count2){
            a=a->next;
            count1--;
        }
        while(count1<count2){
            b=b->next;
            count2--;
        }
        while(a!=b){
             a=a->next;
            b=b->next;
        }
        return a;
    }
};
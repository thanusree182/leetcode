/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* iter=head;
       int len=0;
       while(iter){
           len++;
           iter=iter->next;
       }
        int i=0;
        if(len == n) //first element from beginning
        return head -> next;
        for(iter = head; i < len - n-1; i++) iter = iter -> next;
        iter->next=iter->next->next;
        
        return head;
       
    }
};



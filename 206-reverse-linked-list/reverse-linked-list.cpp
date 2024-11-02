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
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *nextNode;
        while(curr!=NULL){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
        // 	 ListNode* prev=NULL;
        // ListNode* cur=head;
        // ListNode* n;
        // while(cur!=NULL){
        //     n=cur->next;
        //     cur->next=prev;
        //     prev=cur;
        //     cur=n;
        // }
        // return prev;
        // ListNode *curr = head;
        // ListNode *prev = NULL;
        // // ListNode *temp;
        // while(curr != NULL){
        //     ListNode *temp = curr->next;
        //   // temp = curr->next;
        //    curr->next = prev;
        //     curr = temp;
        //     prev = curr;
        // }
        // return prev;
        
    }
};
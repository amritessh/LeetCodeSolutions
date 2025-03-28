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
        ListNode* dummy = new ListNode(0, head);

        // ListNode* dummy(0);
        ListNode* slow = dummy;
        ListNode* fast = head;
          
        while(n>0){
            fast = fast->next;
            n--;}
        
        while(fast){
            slow = slow->next;
            fast = fast->next;
            // curr = curr->next;
        }
        
        slow->next = slow->next->next;
        // return head;
        return dummy->next;
    }
};
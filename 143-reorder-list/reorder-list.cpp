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
    void reorderList(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        //finding the middle node of the linked list
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //reversing the linked list
        
        ListNode* curr = slow->next;
        ListNode* prev = slow->next = NULL;
        ListNode* nextNode;
        while(curr){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        //merge the lists
        curr = prev;
        ListNode* first = head;
        
        while(curr){
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = curr->next;
            
            first->next = curr;
            curr->next = tmp1;
            
            
            first = tmp1;
            curr = tmp2;
        }
        
        
    }
};
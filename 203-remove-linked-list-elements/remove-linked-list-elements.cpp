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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = new ListNode(0);
        temp->next = head;
        
        
        ListNode* curr = head;
        ListNode* prev = temp;
        ListNode* toDelete = NULL;
        
        
        
        while(curr){
            if(curr->val == val){
            prev->next = curr->next;
            toDelete = curr;
        }
            else{
                prev = curr;
            }
            
            curr = curr->next;
            
            if(toDelete){
                delete toDelete;
                toDelete = NULL;
            }  
        }
        
        ListNode *ret = temp->next;
        delete temp;
        return ret;
    }
        
};
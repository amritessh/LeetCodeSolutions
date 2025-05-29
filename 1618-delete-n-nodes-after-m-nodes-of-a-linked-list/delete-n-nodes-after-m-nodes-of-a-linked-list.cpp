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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* curr=head;
        ListNode* last=head;

        while(curr!=NULL){
            int mC = m, nC = n;
            while(curr && mC>0){
            last = curr;
            curr = curr->next;
            mC--;
        }

        while(curr && nC>0){
            curr = curr->next;
            nC--;
        }

        last->next = curr;
    }
    return head;
    }
};
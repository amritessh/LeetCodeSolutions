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
    string gameResult(ListNode* head) {
        ListNode* even = head;
        int evenPoints = 0;
        int oddPoints = 0;

        // Traverse through the linked list assigning points
        while (even != nullptr) {
            ListNode* odd = even->next;
            if (even->val > odd->val) {
                evenPoints += 1;
            } else {
                oddPoints += 1;
            }
            even = odd->next;
        }

        // Return the winning team
        if (oddPoints > evenPoints) {
            return "Odd";
        } else if (oddPoints < evenPoints) {
            return "Even";
        } else {
            return "Tie";
        }
    }
};
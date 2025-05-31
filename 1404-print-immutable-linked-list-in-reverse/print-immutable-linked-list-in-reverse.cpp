/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        ImmutableListNode* curr;
        ImmutableListNode* end = NULL;

        while(head!=end){
            curr = head;
            while(curr->getNext()!=end){
                curr = curr->getNext();
            }

            curr->printValue();
            end = curr;
        }
    }
};
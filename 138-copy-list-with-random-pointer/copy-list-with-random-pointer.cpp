/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head==NULL) return NULL;
        Node* curr = head;
        
    //making copy of the list every node only by using next pointer for first pass
    //new list with same values  
        
        while(curr!=NULL){
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }
        
    //copy of random pointers 
    //we want the curr pointer to come back to point to head for another pass
        curr = head;
        while(curr!=NULL){
            if(curr->random!=NULL){
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;  
        }
        
    //separation of the lists
        curr = head;
        Node* newHead = head->next;
        Node* newCurr = curr->next;
        
        while(curr){
            curr->next = newCurr->next;
            curr = curr->next;
            
            if(curr){
            newCurr->next = curr->next;
            newCurr = newCurr->next;
        }
        }
            
            return newHead;
        
    }
};
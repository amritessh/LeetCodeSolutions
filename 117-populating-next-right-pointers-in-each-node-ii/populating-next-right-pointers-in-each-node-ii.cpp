/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        Node *curr = root;
        Node *dummy = new Node(0);  // Dummy node to track next level's start
        
        while (curr) {
            Node *tail = dummy;  // Tail to build the next level's linked list
            while (curr) {
                // Link left child
                if (curr->left) {
                    tail->next = curr->left;
                    tail = tail->next;
                }
                // Link right child
                if (curr->right) {
                    tail->next = curr->right;
                    tail = tail->next;
                }
                curr = curr->next;  // Move to next node in current level
            }
            curr = dummy->next;  // Move to the next level
            dummy->next = nullptr;  // Reset dummy for the next iteration
        }
        delete dummy;  // Free dummy node (optional)
        return root;
    }
};
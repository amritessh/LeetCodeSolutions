/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     int parentVal = root->val;
    //     int pVal = p->val;
    //     int qVal = q->val;

    //     if(pVal> parentVal && qVal > parentVal){
    //         return lowestCommonAncestor(root->right, p, q);
    //     }

    //     else if (pVal < parentVal && qVal < parentVal) {
    //         // If both p and q are lesser than parent
    //         return lowestCommonAncestor(root->left, p, q);
    // }
    // else{
    //     return root;
    // }

        if (!root || !p || !q) {
            return nullptr;
        }
        if (max(p->val, q->val) < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (min(p->val, q->val) > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }

    }
};
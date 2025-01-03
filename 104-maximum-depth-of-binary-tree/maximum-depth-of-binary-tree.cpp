/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return {};
        // int left = maxDepth(root->left);
        // int right = maxDepth(root->right);
        // int mx = max(left,right);

        // return 1+mx;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
            
            
    }
};
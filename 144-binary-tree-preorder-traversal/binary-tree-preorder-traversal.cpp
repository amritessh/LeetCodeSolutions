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
    
    vector<int> preorderTraversal(TreeNode* root) {
        //morris traversal        
        vector<int> output;
        TreeNode* node = root;
        while (node != nullptr) {
            if (node->left == nullptr) {
                output.push_back(node->val);
                node = node->right;
            } else {
                TreeNode* predecessor = node->left;
                while (predecessor->right != nullptr &&
                       predecessor->right != node) {
                    predecessor = predecessor->right;
                }
                if (predecessor->right == nullptr) {
                    output.push_back(node->val);
                    predecessor->right = node;
                    node = node->left;
                } else {
                    predecessor->right = nullptr;
                    node = node->right;
                }
            }
        }
        return output;




        //iterative
        // if(!root) return {};

        // stack<TreeNode*> stk;
        // vector<int> res;

        // stk.push(root);
        // while(!stk.empty()){
        //     root = stk.top();// find the top element in the stack 
        //     stk.pop();

        //     res.push_back(root->val);

        //     if(root->right){
        //         stk.push(root->right);
        //     }

        //     if(root->left){
        //         stk.push(root->left);
        //     }
        // }
        // return res;

    //recursive
    //     vector<int> res;
    //     preorder(root,res);
    //     return res;
    // }

    // void preorder(TreeNode* root, vector<int>& res){
    //     if(root){
    //         res.push_back(root->val);
    //         preorder(root->left,res);
    //         preorder(root->right,res);
    //     }
    }
    
};
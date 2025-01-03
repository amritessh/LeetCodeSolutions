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

        if(!root) return {};

        stack<TreeNode*> stk;
        vector<int> res;

        stk.push(root);
        while(!stk.empty()){
            root = stk.top();// find the top element in the stack 
            stk.pop();

            res.push_back(root->val);

            if(root->right){
                stk.push(root->right);
            }

            if(root->left){
                stk.push(root->left);
            }
        }
        return res;


        // vector<int> res;
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
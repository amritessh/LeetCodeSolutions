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
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* curr = root;

        if(!root) return{};

        while(!stk.empty() || curr){
            
            while(curr){
                stk.push(curr);
                curr = curr->left;
            }

            curr = stk.top();
            stk.pop();
            res.push_back(curr->val);
            curr = curr->right;


        }

        return res;


    //     vector<int> inorderRes;
    //     // if(!root) return {};
    //     inorder(root,inorderRes);
    //     return inorderRes;
    // }
    //     void inorder(TreeNode* root, vector<int>& res){

    //     if(root){
    //     inorder(root->left,res);
    //     res.push_back(root->val);
    //     inorder(root->right,res);
    //     }
        
    }
};
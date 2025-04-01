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
   
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;

        TreeNode* curr = root;

        while(!stk.empty() || curr){
            while(curr){
                res.push_back(curr->val);
                stk.push(curr);
                curr= curr->right;
            }

            curr = stk.top();
            stk.pop();
            curr=curr->left;
        }

        // return 
        reverse(res.begin(),res.end());
        return res;


    // vector<int> res;
    //     postorder(root, res);
    //     return res;
    // }

    // void postorder(TreeNode* root, vector<int>& res){
    //     if(root){
    //     postorder(root->left,res);
    //     postorder(root->right,res);
    //     res.push_back(root->val);
    //     }
    }
};
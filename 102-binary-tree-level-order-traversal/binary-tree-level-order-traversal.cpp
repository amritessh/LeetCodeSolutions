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
    
    //recursive solution helper function
    vector<vector<int>> levels;
    void helper(TreeNode* node, int level){
        if(levels.size() == level) levels.push_back(vector<int>());
        levels[level].push_back(node->val);
        if(node->left != nullptr) helper(node->left, level+1);
        if(node->right != nullptr) helper(node->right, level+1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        //recursion
        if(root==nullptr) return levels;
        helper(root,0);
        return levels;        
        
        //iterative
        // vector<vector<int>> ans;
        // queue<TreeNode*> q;
        // if (root) {
        //     q.push(root);
        // }
        // TreeNode* cur;
        // while (!q.empty()) {
        //     int size = q.size();
        //     ans.push_back(vector<int>());
        //     for (int i = 0; i < size; ++i) {		// traverse nodes in the same level
        //         cur = q.front();
        //         q.pop();
        //         ans.back().push_back(cur->val);		// visit the root
        //         if (cur->left) {
        //             q.push(cur->left);				// push left child to queue if it is not null
        //         }
        //         if (cur->right) {
        //             q.push(cur->right);				// push right child to queue if it is not null
        //         }
        //     }
        // }
        // return ans;
    
    }
};
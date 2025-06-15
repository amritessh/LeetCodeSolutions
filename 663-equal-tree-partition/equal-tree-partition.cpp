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
    bool checkEqualTree(TreeNode* root) {
        unordered_map<int, int> map;
        int sum = getsum(root, map);
        if(sum == 0)return map[sum] > 1;
        return sum%2 == 0 && map.count(sum/2);
    }
    
    int getsum(TreeNode* root,  unordered_map<int, int>& map){
        if(root == NULL)return 0;
        int cur = root->val + getsum(root->left, map) + getsum(root->right, map);
        map[cur]++;
        return cur;
    }
};
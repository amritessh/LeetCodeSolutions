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
    void inorder(TreeNode* root, vector<int>& nums) {
        if (!root) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

    int closestValue(TreeNode* root, double target) {
        vector<int> nums;
        inorder(root, nums);
        auto cmp = [&](int a, int b) {
            double da = abs(a - target), db = abs(b - target);
            return da < db || (da == db && a < b);
        };
        return *min_element(nums.begin(), nums.end(), cmp);
    }
};
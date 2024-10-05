/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool validate(TreeNode* root, long long minval, long long maxval) {
        if (root == NULL)
            return true;
        if (!(minval < root->val && root->val < maxval))
            return false;

        return validate(root->left, minval, root->val) &&
               validate(root->right, root->val, maxval);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};

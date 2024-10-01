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
    vector<int> array;

    void inorder(TreeNode* root){
        if(root == NULL) return;

        inorder(root->left);
        array.push_back(root->val);
        inorder(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        //inorder traversal for BST is sorted, left<root<right
        //apply two sum -> 2 pointer approach as array is sorted

        int left = 0, right = array.size()-1;
        while(left < right){
            if(array[left] + array[right] == k) return true;
            else if(array[left] + array[right] < k) left++;
            else right--;
        }
        return false;
    }
};
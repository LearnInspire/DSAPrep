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
    /*Approach 3: we can solve it using bst iterator approach as well explained by Striver
    /*Approach 2: store the values in hashmap or set & then find k - root's value in set, if there then return true
    TC:O(n), SC:O(n)   */
    unordered_set<int> st;
    bool findTarget(TreeNode* root, int k){
        if(root == NULL) return false;
        if(st.find(k-root->val) != st.end()) return true;
        st.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
    
    /* Approach1: storing bst in array & applying 2 pointer on array just like 2 sum, TC:O(n) SC:O(n)
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
        }*/
};
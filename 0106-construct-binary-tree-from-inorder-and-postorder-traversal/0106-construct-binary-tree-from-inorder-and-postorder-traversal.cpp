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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> inhashmap;
        for(int i = 0; i<inorder.size(); i++){
            inhashmap[inorder[i]] = i;
        }
        TreeNode* root = build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, inhashmap);
        return root;
    }

    TreeNode* build(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, map<int, int>& inhashmap){
        if(inStart > inEnd || postStart > postEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = inhashmap[postorder[postEnd]];
        int numsLeft = inRoot - inStart;

        root->left = build(inorder, inStart, inRoot - 1, postorder, postStart, postStart+numsLeft-1, inhashmap);
        root->right = build(inorder, inRoot+1, inEnd, postorder, postStart+numsLeft, postEnd-1, inhashmap);
        
        return root;
    }
};
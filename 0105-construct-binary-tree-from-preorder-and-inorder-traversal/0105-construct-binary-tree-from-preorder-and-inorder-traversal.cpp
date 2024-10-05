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
 /* Create a map to store the inorder indexes.
Call the function constructTree with all 7 parameters as shown above.
In the recursive function, first check the base case, if (preStart,>preEnd || inStart> inEnd) then return NULL.
Construct a node (say root) with the root value( first element of preorder). 
Find the index of the root, say elem from the hashmap.
Find the number of elements ( say nElem) in the left subtree  = elem – inStart
 Call recursively for the left subtree with correct values (shown in the above table) and store the answer received in root->left.
Call recursively for the right subtree with correct values (shown in the above table) and store the answer received in root->right.
Return root */

class Solution {
public:
    map<int,int>mp; //declared outside function to remove tle
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        TreeNode* root=build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
        return root;
    }

    TreeNode* build(vector<int>& preorder,int prestart,int preend,vector<int>& inorder,int instart,int inend)
    {
        if(prestart>preend || instart>inend)    return NULL; //Terminating statement
        TreeNode* root=new TreeNode(preorder[prestart]);
        int rootpos=mp[preorder[prestart]]; //defined index of root alternatively mp[root->val];
        int leftnums=rootpos-instart; //defined numbers to the left of root
        root->left=build(preorder,prestart+1,prestart+leftnums,inorder,instart,rootpos-1);
        root->right=build(preorder,prestart+leftnums+1,preend,inorder,rootpos+1,inend);
        return root;
    }
};


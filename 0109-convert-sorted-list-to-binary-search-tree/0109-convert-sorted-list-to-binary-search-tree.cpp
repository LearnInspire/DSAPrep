/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        //edge case, if LL is null
        if(head == NULL) return NULL;

        // LL is having just one element, make that single node in a tree
        if(head->next == NULL) return new TreeNode(head->val);

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* slow_prev =   NULL;
        //to find the middle of LL & make it a root bcz it's sorted & we're aiming to make a balanced BST   
        while(fast != NULL && fast->next != NULL){
            slow_prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        //slow is definitely gonna point to middle
        TreeNode* root = new TreeNode(slow->val);

        //remove the link between left subtree's last node which is LL to the root which is next element in LL
        slow_prev->next = NULL;

        //recursion call for left subtree
        root->left = sortedListToBST(head);

        //recursion call for right subtree
        root->right = sortedListToBST(slow->next);

        return root;
    }
};
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
class Solution {
public:
    int findLength(ListNode* head){
        int length = 0;
        while(head != NULL){
            head = head->next;
            length++;
        }
        return length;
    }

    ListNode* swapNodes(ListNode* head, int k) {
        //kth node from beginnning
        //kth node from end-> (Length-k+1)th node from beginning
        
        int L = findLength(head);
        //1st kth node from start
        int k_1 = k;
        ListNode* node1 = head;
        while(k_1 > 1){
            node1 = node1->next;
            k_1 --;
        }

        //kth node from end, use formula, L-k+1
        int k_2 = L - k + 1;
        ListNode* node2 = head;

        while(k_2 > 1){
            node2 = node2->next;
            k_2 --;
        }

        swap(node1->val, node2->val);
        return head;
    }
};
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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) return NULL;

        ListNode* prevSlow = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            prevSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
            //skipping one slow step so that when fast reaches the end or null, 
            //depending upon the length of LL, whether it's odd or even
        }

        prevSlow->next = slow->next;
        delete(slow);

        return head;
    }
};
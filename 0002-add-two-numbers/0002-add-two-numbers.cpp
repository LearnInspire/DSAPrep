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
    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
        ListNode* dummyNode = new ListNode(0);
        ListNode* curr = dummyNode;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        int carry = 0;
        while(temp1 != NULL || temp2 != NULL){
            int sum = carry;

            if(temp1 != NULL) {
            sum += temp1->val;
            temp1 = temp1->next;
            }

            if(temp2 != NULL) {
            sum += temp2->val;
            temp2 = temp2->next;
            }
            ListNode* sumList = new ListNode(sum % 10);
            carry = sum / 10;
            curr->next = sumList;
            curr = curr->next;
        }
        if(carry){
            ListNode* sumList = new ListNode(carry);
            curr->next = sumList;
        }
        return dummyNode->next;
    }
};
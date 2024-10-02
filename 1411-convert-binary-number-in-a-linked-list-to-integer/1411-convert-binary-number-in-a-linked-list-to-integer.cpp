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
    //Brute: reverse the LL & then calculate decimal->takes 2 iterations
    //Better: find length of the LL & then compute with power of (length - 1)-> takes 2 iterations
    //Optimal: assume we're at lat node so 2^0 x val, but on moving we find there's other nodes so multiply the whole computed result by 2
    // 2 (2^1*val+2^0*val) + 2^0 * val
    int getDecimalValue(ListNode* head) {
        int number = 0;
        ListNode* temp = head;
        while(temp != NULL){
            number *= 2;
            number += temp->val;
            temp = temp->next;
        }
        return number;
    }
};
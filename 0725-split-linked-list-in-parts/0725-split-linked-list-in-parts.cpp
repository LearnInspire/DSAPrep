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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        //length of the linked list
        int length = 0;
        ListNode* curr = head;
        while(curr != NULL){
            length++;
            curr= curr->next;
        }

        int bucketSize = length / k;
        int extraNodes = length % k;

        vector<ListNode*> result(k, NULL);
        curr = head;
        ListNode* prev = curr;

        for(int i = 0 ; i<k; i++){
            result[i] = curr;
            
            for(int count = 1; count <= bucketSize + (extraNodes > 0 ? 1 : 0); count++){
                prev = curr;
                curr = curr->next;
            }
            if(prev != NULL)
                prev -> next = NULL;
            extraNodes--;

        }
        return result;
    }
};
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
private:
    ListNode* findNthNode(ListNode* temp, int k){
        int cnt = 1;
        while(temp != NULL){
            if(cnt == k) return temp;
            cnt++;
            temp = temp->next;
        }
        return temp;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* tail = head;
        int length = 1;
        while(tail->next != NULL){
            length++;
            tail = tail->next;
        }

        if(k % length == 0) return head;

        k = k % length;

        //attach the tail to the head
        tail->next = head;

        ListNode* newLastNode = findNthNode(head, length-k);

        head = newLastNode->next;
        newLastNode->next = NULL;

        return head;
    }
};
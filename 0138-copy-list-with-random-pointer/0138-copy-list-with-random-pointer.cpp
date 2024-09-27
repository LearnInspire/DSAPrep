/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head == NULL) return NULL;

        Node* curr = head;
        Node* prev = NULL;
        Node* newHead = NULL;

        unordered_map <Node*, Node*> mp;

        while(curr != NULL){
            Node* temp = new Node(curr->val); //curr ke corresponding yeh node bna
            mp[curr] = temp; //storing mapping in map

            if(newHead == NULL){
                newHead = temp;
                prev = newHead;
            }
            else{
                prev->next = temp;
                prev = temp;
            }
            curr = curr->next;
        }

        //fill random pointers in secon traversal
        curr = head;
        Node* newCurr = newHead;

        while(curr  != NULL){
            if(curr->random == NULL){
                newCurr->random == NULL;
            }
            else{
                newCurr->random = mp[curr->random];
            }

            curr = curr->next;
            newCurr = newCurr->next;
        }

        return newHead; //head of the deep copy LL created
    }
};
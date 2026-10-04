/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 Two pointer method:
 We can use two pointers to traverse the list one pointer will move with 2 nodes at a time and second will be move one node at a time. 
 If there is a cycle they will surely be on same node , then we can return true 

 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode *p1 = head, *p2 = head;
        while(p2 != nullptr) {
            p2 = p2 -> next;
            if (p2 == nullptr) {
                return false;
            } else {
                p2 = p2 -> next;
            }
            p1 = p1 -> next;
            if (p1 == p2) {
                return true;
            }
        }
        return false;
    }
};

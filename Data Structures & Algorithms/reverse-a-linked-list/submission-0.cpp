/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

 two things to keep in mind :
  - after reversing the head will point to the last element of the list 
  - we need to reverse the direction of pointers between the linked nodes 

for this we need to traverse the list from head to the tail and keep reversing the pointer
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *p = nullptr;
        ListNode *n = nullptr;
        while(head != nullptr) {
            n = head->next;
            head->next = p;
            p = head;
            head = n;
        }
        head = p;
        return head;
    }
};

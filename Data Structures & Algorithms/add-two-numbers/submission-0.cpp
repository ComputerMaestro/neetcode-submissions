/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

Traversing both simultneuously:
Start from first elements create a new node which will contain the addition of both the lists and add them store first digit of addition in this new node and the extra digit (if any) - carry over - will be stored for next elements iteration (for separating the digits after addition can be done by calculating mod of addition by 10)
With next element in the both list if ther is any carry , we will add that as well and update carry again 
on the last node if carry is not zero then we will have to create a new node 

This will have time complexity will O(n) where n is n number of digits in larger list 
And the space complexity will be O(n) as we need this extra space for storing , or O(1) if we dont' consider this as extra , becaus we will be only using few variables 
We can also use onhe of the list and do in place addition in that list to even avoid this O(n) space if needed. 
if one list if shorter than other , just copy the remaining elements from the longer list to the new list 

 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *addHead = new ListNode(), *curL1 = l1, *curL2 = l2, *curNewL = addHead, *p = nullptr;
        int carry = 0;
        while(curL1 != nullptr || curL2 != nullptr) {
            int addition = carry;
            if (curL1 != nullptr) {
                addition += curL1 -> val;
                curL1 = curL1 -> next;
            }
            if(curL2 != nullptr) {
                addition += curL2 -> val;
                curL2 = curL2 -> next;
            }
            curNewL -> val = addition % 10;
            carry = addition / 10;
            p = curNewL;
            curNewL -> next = new ListNode();
            curNewL = curNewL -> next;
        }
        if (carry) {
            curNewL -> val = carry;
        } else {
            p -> next = nullptr;
        }
        return addHead;
    }
};

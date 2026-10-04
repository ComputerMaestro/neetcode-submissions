/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

 Merge sort algo:
 we will need two pointers , one for list 1 and for 2 
 we will compare the pointers value and whichever larger we will set the current new list node to that value because that will be the smallest value currently (as in from the pointers to the end of their corresponding lists)
 then move the pointer for that value to next node in list keep the other pointer list on same node 
 we continue doing this until end of both the lists 

 in this we are traversing the list nodes of both once and their is only few extra variables we will be needing , therefore 
 the time complexity will be O(m + n) where m is length of first list and n is of second list 
 the space complexity will be O(1)
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr) {
            return nullptr;
        }
        ListNode *curL1 = list1, *curL2 = list2, *newList = new ListNode(), *curNode = newList, *p = new ListNode();
        p -> next = curNode;
        while(curL1 != nullptr || curL2 != nullptr) {
            if (curL1 == nullptr) {
                curNode -> val = curL2 -> val;
                curL2 = curL2 -> next;
            } else if (curL2 == nullptr) {
                curNode -> val = curL1 -> val;
                curL1 = curL1 -> next;
            } else {
                if (curL1 -> val <= curL2 -> val) {
                    curNode -> val = curL1 -> val;
                    curL1 = curL1 -> next;
                } else {
                    curNode -> val = curL2 -> val;
                    curL2 = curL2 -> next;
                }
            }
            curNode -> next = new ListNode();
            p = curNode;
            curNode = curNode -> next;
        }
        p -> next = nullptr;
        return newList;
    }
};

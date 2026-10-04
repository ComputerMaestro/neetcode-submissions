/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

Basically , we need to reorder the list in alternative order of first and last elements iteratively 
Simple solution is to 
put a current node pointer to the first node
if next node is not null then traverse to the last node and put it as next of current node (which is first node)
then leave next node (which was originally second node in the list )
then chekc if next ndoe is last node and again traverse to the last node and adjust pointers so that it some after the current node (which is second node originally )

and so on until current node is last node 

but this will take 
n-1 , n-3, n-5  => O(n2) time complexity 

Array solution 

we can traverse the list and make a array of pointers which will store pointers to eahc element of the list
then use two pointer method to just adjust the pointers on each node , take one from front and one from back alternatively and then will result in the reordered list

the time complexity since we are only traverse each item in list almost 2 times , => O(n)
and the space needed for the pointers will take => O(n) space complexity

Reverse Half list Method:
Idea is that the reordered list have the same direction of pointing for the first half of elements and the second half elements have reversed the pointer directions (not directly pointing to the previous element but the direction is now to the previous element )
exmaple: 0 -> 1 ..... n-3 -> n-2 -> n-1 , now if we see only second half, the order is n-1, n-2, n-3  so on , that means order is reversed for second

Therefore, If we reverse the second half of the list (basically revesing the pointers in second half, which can be done in O(n) time) and make anotehr list where the head is last node (n-1) from original list
Then we take two pointers startPointer at the head and lastPointer at the last element (which is first element of the reverse half list )
Now, we basically have two lists and we just have to merge them 

In this we are only using two pointers extra, which gives me us O(1) space complexity 
and we are traversing each elements only twice , => O(n) time complexity
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) {
            return;
        }

        // find the half point of list 
        ListNode* mid = head;
        ListNode* last = head;
        int i = 0;
        for(;last->next != nullptr; i++) {
            last = last -> next;
            if(i > 0 && i%2 == 0) {
                mid = mid->next;
            }
        }
        if (i%2 == 0) {
            mid = mid -> next;
        }

        // reverse the second half of the list
        last = mid->next;
        mid->next = nullptr;
        ListNode* p = nullptr;
        ListNode* n = last->next;
        while(last != nullptr) {
            n = last->next;
            last->next = p;
            p = last;
            last = n;
        }
        last = p;


        ListNode* curL1 = head;
        ListNode* curL1n = head -> next;
        ListNode* curL2n = last -> next;
        while(last != nullptr) {
            curL1n = curL1 -> next;
            curL2n = last -> next;
            curL1 -> next = last;
            last -> next = curL1n;
            curL1 = curL1n;
            last = curL2n;
        }
    }
};

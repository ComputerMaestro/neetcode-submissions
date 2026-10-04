/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

 Simple Solution :
 Traverse the list and count the number of elements  => O(n)
 Traverse the list again and remove the sz-nth element => O(n)

 Space complexity is O(1)

 Recursive solution:
 We traverse the list recursively 
 we will initiate a recursion function with next node as the head
 add one to the output of this recursion and cehck if is equal to the nth
 if n+1th then return the pointer 
 else return the previous pointer 
 base case will be 
    curNode is nullptr , return 0 and nullptr
then we can delete the nth pointer from the list 

but this will take O(n) time complexity 
and this will also take O(n) space complexity 

Optimized solution:
Use two pointer 
first pointer will start traversing the list and second pointer will start traversing the list when the first pointer reaches the n+1th element from the start 
That way, when the first pointer reaches last element , the second pointer will be at the n+1th distance from last and will be at the n+1th pointer and then we can remove the nth pointer by adjusting the pointers on n+1 and n-1 elements (from last) 
this will take O(n) and will also traverse the list only once 
and the space complexity will O(1) because we will use only few variables to count and pointers

 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr || head -> next == nullptr) {
            return nullptr;
        }
        ListNode *dummy = new ListNode();
        ListNode *left = dummy, *right = dummy;
        dummy -> next = head;
        int i = 0;
        while(right != nullptr) {
            right = right -> next;
            if(i < n+1) {
                i++;
            } else {
                left = left -> next;
            }
        }
        if (left -> next == head) {
            head = left -> next -> next;
        }
        left -> next = left -> next -> next;
        return head;
    }
};

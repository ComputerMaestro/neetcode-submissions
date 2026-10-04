/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

 Here we can use pointer method:
 Traverse the list in blocks of k elements 
 we need to reverse this block and keep the reference to the nodes at starting and ending of original block 
 we can reverse the list in one go 
 Once we move to the next block , point the first element in original prev block to the last elements of the second original block , for thta we neeed to store the prev last and cur last node references 

 But this will take only once pass through the list and O(1) space complexity
 If the last block does not have the k elements then we need to re reverse it 
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *reversed = nullptr, *curNode = head, *p = nullptr, *n, *prevL = new ListNode(), *curL = head;
        while(curNode != nullptr) {
            int i = 0;
            for(; i < k && curNode != nullptr; i++) {
                n = curNode -> next;
                curNode -> next = p;
                p = curNode;
                curNode = n;
            }
            if (curNode == nullptr) {
                if (i < k) {
                    curNode = p;
                    p = nullptr;
                    while(curNode != nullptr) {
                        n = curNode -> next;
                        curNode -> next = p;
                        p = curNode;
                        curNode = n;
                    }
                }
            }
            if (reversed == nullptr) {
                reversed = p;
            }
            prevL -> next = p;
            p = nullptr;
            prevL = curL;
            curL = curNode;
        }
        return reversed;
    }
};

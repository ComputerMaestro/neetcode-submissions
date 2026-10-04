/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

 Sorted Linked List Solution:
We can find the smallest value amount all the lists in each iteration within logk time if we maintain a sorted list of cur elements from each list and as we take elements fro teh list we keep maintaining the sorted order.
In this way we in worst we can do this in O(nklogk) time complexity 
and the extra vector we will nee to store the cur top values from each list will be O(k)
 */

 class Solution {
    vector<ListNode*> *sortedNodes;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);

        for (ListNode* list : lists) {
            if (list != nullptr) {
                minHeap.push(list);
            }
        }

        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        while (!minHeap.empty()) {
            ListNode* node = minHeap.top();
            minHeap.pop();
            cur->next = node;
            cur = cur->next;

            node = node->next;
            if (node != nullptr) {
                minHeap.push(node);
            }
        }
        return res->next;
    }
};



// class Solution {
//     vector<ListNode*> *sortedNodes;
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         sortedNodes = new vector<ListNode*>();
//         for(int i = 0; i < lists.size(); i++) {
//             insertInSortedNodes(lists[i]);
//         }
//         ListNode *newList = this -> sortedNodes[0];

//     }

//     void insertInSortedNodes(ListNode *node) {
//         if ((this -> sortedNodes).size() == 0) {
//             (this -> sortedNodes).push_back(node);
//             return;
//         }
//         int startIdx = 0, endIdx = this -> sortedNodes.size()-1;
//         while(endIdx - startIdx < 1) {
//             int mid = (endIdx - startIdx) / 2;
//             if (this -> sortedNodes[startIdx + mid] -> val < node -> val) {
//                 startIdx = startIdx + midIdx + 1;
//             } else {
//                 endIdx = midIdx;
//             }
//         }
//         if ((this -> sortedNodes).size() == 1) {
//             if (this -> sortedNodes[startIdx] -> val < node -> val) {
//                 if (startIdx + 1 >= this -> sortedNodes.size()) {
//                     this -> sortedNodes.push_back(node);
//                 } else {
//                     this -> sortedNodes.insert(this -> sortedNodes.begin(), startIdx + 1, node);
//                 }
//             } else {
//                 this -> sortedNodes.insert(this -> sortedNodes.begin(), startIdx, node);
//             }
//             return;
//         }
//     }
// };

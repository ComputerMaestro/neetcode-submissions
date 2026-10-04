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

Brute Force solution:
Traverse the list and make copies of each element
Then again traverse the list 
for each element with not null random pointer , each each elements in original list wehre the node to which cur node is pointing is present and make the same connection in the copied element 
we will have to get the position of each element where the random pointer is pointing 

This will in worst case give us O(n2) time complexity because we have to traverse whole list (n) for each element of the list 


HashMap Method :
Traverse the list and make copies and connect them and put random pointers as null for all copied nodes
We Maintain a map of original list node address to their corresponding copied node address
Traverse the original list again and for each node get random pointer value and using the hashmap get its copy's address and for current node get its own copy's address as well. And pointer this copy node random pointer to the copy of the node where random pointer in original list was pointing to. 

Here, the algo will traverse the list twice and that gives us O(n) time complexity 
Since we are using hashmap => O(n) space complexity 


*/

# include <map>

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) {
            return nullptr;
        }
        map<Node*, Node*> nodeMapping;
        Node *newHead = new Node(head -> val), *curNode = head -> next;
        nodeMapping[head] = newHead;
        for(Node *curNewNode = newHead;curNode != nullptr; curNode = curNode -> next) {
            Node *tmp = new Node(curNode -> val);
            curNewNode -> next = tmp;
            curNewNode = tmp;
            nodeMapping[curNode] = tmp;
        }

        curNode = head;
        for(Node *curNewNode = newHead; curNewNode != nullptr; curNewNode = curNewNode -> next, curNode = curNode -> next) {
            curNewNode -> random = nodeMapping[curNode -> random];
        }
        return newHead;
    }
};

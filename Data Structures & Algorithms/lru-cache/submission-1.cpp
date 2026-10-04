struct Node {
    int key;
    int val;
    Node *next;
    Node *prev;
    };
class LRUCache {
    unordered_map<int, Node*> keyPointerMap;
    Node *lru;
public:
    LRUCache(int capacity) {
        lru = new Node();
        Node *curNode = lru;
        curNode -> val = -1;
        curNode -> key = -1;
        for(; capacity > 1; capacity--) {
            curNode -> next = new Node();
            curNode -> val = -1;
            curNode -> key = -1;
            curNode -> next -> prev = curNode;
            curNode = curNode -> next;
        }
        curNode -> next = lru;
        lru -> prev = curNode;
    }
    
    int get(int key) {
        if (keyPointerMap[key]) {
            Node *node = keyPointerMap[key];
            // if node is already lru then we just need shift lru to next node and the cur node will become most recently used automatically
            if (node == lru) {
                lru = node -> next;
            } else { 
                // remove the node from the list first and adjust the adjacent nodes pointers 
                node -> next -> prev = node -> prev;
                node -> prev -> next = node -> next;

                // put node before lru, as that position signifies most recentsly used node 
                node -> next = lru;
                node -> prev = lru -> prev;
                lru -> prev -> next = node;
                lru -> prev = node;
            }
            return node -> val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(keyPointerMap[key]) {
            Node *node = keyPointerMap[key];
            node -> val = value;
            if (node == lru) {
                lru = node -> next;
            } else { 
                // remove the node from the list first and adjust the adjacent nodes pointers 
                node -> next -> prev = node -> prev;
                node -> prev -> next = node -> next;

                // put node before lru, as that position signifies most recentsly used node 
                node -> next = lru;
                node -> prev = lru -> prev;
                lru -> prev -> next = node;
                lru -> prev = node;
            }
        } else {
            if (lru -> key < 0) {
                keyPointerMap[key] = lru;
                lru -> key = key;
                lru -> val = value;
            } else {
                keyPointerMap[key] = lru;
                keyPointerMap.erase(lru -> key);
                lru -> key = key;
                lru -> val = value;
            }
            lru = lru -> next;
        }
    }
};

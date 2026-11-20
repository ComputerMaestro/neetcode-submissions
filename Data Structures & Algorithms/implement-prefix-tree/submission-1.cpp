struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEnd;
};

class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curNode = root;
        for(char l: word) {
            if (curNode -> children[l] == nullptr) {
                curNode -> children[l] = new TrieNode();
            }
            curNode = curNode -> children[l];
        }
        curNode -> isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(char l: word) {
            if (node -> children[l] == nullptr) {
                return false;
            }
            node = node -> children[l];
        }
        return node -> isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char l: prefix) {
            if (node -> children[l] == nullptr) {
                return false;
            }
            node = node -> children[l];
        }
        return true;
    }
};

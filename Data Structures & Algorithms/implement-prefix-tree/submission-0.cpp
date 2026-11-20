struct TrieNode {
    vector<TrieNode*> children = vector<TrieNode*>(26, nullptr);
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
            if (curNode -> children[l - 'a'] == nullptr) {
                curNode -> children[l - 'a'] = new TrieNode();
            }
            curNode = curNode -> children[l - 'a'];
        }
        curNode -> isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(char l: word) {
            if (node -> children[l - 'a'] == nullptr) {
                return false;
            }
            node = node -> children[l - 'a'];
        }
        return node -> isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char l: prefix) {
            if (node -> children[l - 'a'] == nullptr) {
                return false;
            }
            node = node -> children[l - 'a'];
        }
        return true;
    }
};

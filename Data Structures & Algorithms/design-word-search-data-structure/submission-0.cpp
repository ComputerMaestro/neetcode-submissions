struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEnd;
}; 

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (char c: word) {
            if(node -> children.find(c) == node -> children.end()) {
                node -> children[c] = new TrieNode();
            }
            node = node -> children[c];
        }
        node -> isEnd = true;
        return;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        stack<pair<int, TrieNode*>> st;
        for (const auto& [key, value]: root -> children) {
            if (word[0] == '.') {
                st.push({0, value});
            } else if (word[0] == key) {
                st.push({0, value});
            }
        }
        while(!st.empty()) {
            pair<int, TrieNode*> p = st.top();
            st.pop();
            if (p.first >= word.size() - 1) {
                if (p.second -> isEnd) {
                    return true;
                }
            } else {
                if (word[p.first + 1] == '.') {
                    for (const auto& [key, value]: p.second -> children) {
                        st.push({p.first + 1, value});
                    }
                } else if (p.second -> children.find(word[p.first + 1]) != p.second -> children.end()) {
                    st.push({p.first + 1, p.second -> children[word[p.first + 1]]});
                }
            }
        }
        return false;
    }
};

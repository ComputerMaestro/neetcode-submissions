/*
for this make a graph using the wordlist where we need to check which words are neighbours
nieghbours have only one character different from each other 

we will check which of them are one character away from the begin word and start traversing the graph and reach the end word if it is present in wordlist(if not return 0 while buildign the graph)

we can use BFS approach which is more effcient for finding shortest path

time complexity => O(n^2 * l) + O(n) => O(n^2)  l = length of longest word
space complexit will be => O(n)


instead of building a graph we can directly use the wordList to check traversal during BFS
because words on same distance from the begin word will only ned to move to remaining nodes in the wordlist 

we can use queue for this and store the words which are one character different from beginword and remove those from the wordlist and put them in queue
then from queue we will traverse each word in the list which are one character away from any of the words in the queue

that way we will not travel and word twice and the keep moving towards the end node withotu going back to already visited nodes (even if they are connected)

if queue is empty and we did not reach end word then return false

time complexity will be O(n) as all nodes are travelled once 
space complexity will be O(n) for storing in the queue and the path distance in queue

*/

class Solution {
    bool isNeighbourWord(string word, string candidate) {
        int diff = 0;
        for(int i = 0; i < word.size(); i++) {
            if (word[i] != candidate[i]) {
                diff++;
            }
        }
        return diff == 1;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        vector<string> newList;
        for(string word: wordList) {
            if (isNeighbourWord(beginWord, word)) {
                q.push({word, 2});
            } else {
                newList.push_back(word);
            }
        }
        wordList = newList;
        while(!q.empty()) {
            pair<string, int> p = q.front();
            q.pop();
            if (p.first == endWord) {
                return p.second;
            }
            newList = {};
            for(string word: wordList) {
                if (isNeighbourWord(p.first, word)) {
                    q.push({word, p.second+1});
                } else {
                    newList.push_back(word);
                }
            }
            wordList = newList;
        }
        return 0;
    }
};

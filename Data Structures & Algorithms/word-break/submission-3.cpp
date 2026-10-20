/*
First of all we can make a actual hashmap using given dict to check if a sequence of letters excist in the dict or not 

The can parse the letters recursively and for each letter we can first chec if in the dict , if it is present then we can either break or can decide to add next letter as well. Because a bigger letter in the dict can have another smaller work which is also their in the dict 

if we reach the end of string and the last work does not match anything in the dict then return false , if it mathces then return true
now on every index of string we are checking if the words separtion is possible or not . This index can repeate for multiple paths in the recursive tree. So can store the output of each index in a array of boolean , which can be reused . 


*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> dict;
        for (string word: wordDict) {
            dict[word] = true;
        }

        vector<int> memo(s.size(), -1);
        
        string cur = "";

        return dp(s, dict, memo, 0);
    }

    bool dp(string& s, unordered_map<string, bool>& dict, vector<int>& memo, int i) {
        if (i == s.size()) {
            return true;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        string cur = "";
        for (int j = i; j < s.size(); j++) {
            cur.push_back(s[j]);

            if (dict[cur] && dp(s, dict, memo, j + 1)) {
                return memo[i] = true;
            }
        }
        return memo[i] = false;
    }
};

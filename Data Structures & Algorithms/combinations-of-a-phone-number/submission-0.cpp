/*
all the letters which come under a numbers gets added to all the other possible combinations of the remaining digits letters
basically we can find all possible combinations of two numbers and then find the all possible combinatoins suing these previous combinations and combining the next digit letters and so on. 

*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> digitLettersMap = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        vector<string> res;
        for(char c: digitLettersMap[digits[0]]) {
            res.push_back(string(1, c));
        }
        for(int i = 1; i < digits.size(); i++) {
            vector<string> next = {};
            for(char letter: digitLettersMap[digits[i]]) {
                for(string str: res) {
                    next.push_back(str + letter);
                }
            }
            res = next;
        }
        return res;
    }
};

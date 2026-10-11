/*
For creating well-formed parenthesis:
For any closing parenthesis an opened parenthesis should already be present 
also for valid combinations all opened parenthesis should be closed - at the end of the string there should be zero single opened parenthesis

for this we need to mainting a count of opened parenthesis
with every open parentheis choice - increase the count
with every closing parenthesis choice - decrease the count

Backtracking:
because we can eliminate few choices here based on the parenthesis 

time complexity will O(n*2^n)
space complexity will be O(n)
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur = "(";
        bracktracking(res, &cur, 1, n - 1);
        return res;
    }

    void bracktracking(vector<string>& res, string* cur, int open, int remaining) {
        if (remaining == 0 && open == 0) {
            res.push_back(*cur);
            return;
        }

        if (remaining < 0 || open < 0) {
            return;
        }

        *cur = *cur + "(";
        bracktracking(res, cur, open + 1, remaining - 1);
        (*cur).pop_back();
        *cur = *cur + ")";
        bracktracking(res, cur, open - 1, remaining);
        (*cur).pop_back();
        return;
    }
};

/*
if a number sequence is starting from 0 that can never be decoded , because we need a digit in front of zero , which is not possible. this is true any substring of the given string. 

Backtracking:
select a digit or select current digit with next digit 
for any index in the array we have only these two choices. 
Then move to next index. 

if current index element is zero , then no decodes are possible , return zero
so two can only be selected if current element is less equal to 2 , because there is no mapping above 26 
we also cap it on the 6 as well. that is second digit is more than 6 , than also no decoding possible return 0 is all these cases. 

time complexity of O(2^n)
space complexity is O(n) for recursince calls 

DP solution:
number of possible decoding combinations from a current index element is equal to the number of combinations possible from remaining substring from it. 
So we can store the substring combinations in a array to memorize , so that we do not have to recompute them 

time complexity will be O(n) since we not chekcing all substrings again 
space compleixty will be O(n)
*/

class Solution {
public:
    int numDecodings(string s) {
        vector<int> memo(s.size(), -1);
        return dp(s, 0, memo);
    }

    int dp(string& s, int i, vector<int>& memo) {
        if (i >= s.size()) {
            return 1;
        }
        if (s[i] == '0') {
            return 0;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        int c = dp(s, i+1, memo);
        if (i+1 < s.size() && s.substr(i, 2) <= "26") {
            c += dp(s, i+2, memo);
        }
        memo[i] = c;
        return c;
    }
};

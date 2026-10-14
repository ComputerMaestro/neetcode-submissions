/*
Brute Force solution:
we can iteration over all possible sub strings from 0th index and 1th index and so on for all and check for each substring if it is a palindrome and keep tracking the longest one and return it 

time complexity : O(n^3)
space compleixty will be : O(1)

Dynamic Programming: 
We can start from teh start and end elements of the string and check if those two are matching , if yes 
then 
    either move both pointers inward 
    move first pointer 
    move last pointer by one 
if not 
    then move fist opinter 
    move last opinter inward by one

using memoization we can keep storing the values we find in smaller substring as we move inward , which can be reused to avoid dupliate processing. 
*/

class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> memo(s.size(), vector<int>(s.size(), -1));
        int lLen = 1, lStart = 0;
        if(dp(s, memo, 0, s.size()-1, lLen, lStart)) {
            return s;
        }
        return s.substr(lStart, lLen);
    }

    bool dp(string& s, vector<vector<int>>& memo, int start, int end, int& lLen, int& lStart) {
        if (start > end || start >= s.size() || end < 0) {
            return false;
        }
        if (memo[start][end] != -1) {
            return memo[start][end];
        } 
        if (s[start] == s[end]) {
            if (end - start <= 2) {
                memo[start][end] = 1;
            } else {
                memo[start][end] = dp(s, memo, start+1, end-1, lLen, lStart);
            }
            if (memo[start][end] == 1) {
                if (lLen < (end + 1 - start)) {
                    lStart = start;
                    lLen = end + 1 - start;
                }
                return true;
            }
        }
        dp(s, memo, start+1, end, lLen, lStart);
        dp(s, memo, start, end-1, lLen, lStart);
        memo[start][end] = false;
        return false;
    }
};

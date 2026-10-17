class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> memo(text1.size(), vector<int>(text2.size(), -1));
        return dp(text1, text2, memo, 0, 0);
    }

    int dp(string& text1, string& text2, vector<vector<int>>& memo, int i, int j) {
        if (i >= text1.size() || j >= text2.size()) {
            return 0;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        int count = 0;
        if (text1[i] == text2[j]) {
            count += 1 + dp(text1, text2, memo, i+1, j+1);
        } else {
            count += max(dp(text1, text2, memo, i, j+1), dp(text1, text2, memo, i+1, j));
        }
        
        memo[i][j] = count;
        return count;
    }
};

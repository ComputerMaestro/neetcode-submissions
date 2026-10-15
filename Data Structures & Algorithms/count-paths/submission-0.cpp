/*
So on every box we have two choices 

dp:
we will make two recursive internal calls one for right and one for down 
for every square , can also save the nums of paths from that square to the bottom corner in a 2d array 

we can do this two ways 
we can start recursive calling from the top left corner and build the paths 
or we can stasrt from the bottom right ocrner and build the path backward to the top left and each square will depend upon the path built by it previous square on right and down 


*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        int total = 0;
        vector<vector<int>> memo(m, vector<int>(n, 0));
        return dp(memo, 0, 0, m, n);
    }

    int dp(vector<vector<int>>& memo, int row, int col, int m, int n) {
        if (row == m-1 && col == n-1) {
            return 1;
        }
        if (row == m || col == n) {
            return 0;
        }
        if (memo[row][col]) {
            return memo[row][col];
        }
        memo[row][col] = dp(memo, row, col + 1, m, n) + dp(memo, row + 1, col, m, n);
        return memo[row][col];
    }
};

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
        vector<int> memo(n + 1, 0);
        memo[n-1] = 1;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                memo[j] += memo[j+1];
            }
        }
        return memo[0];
    }
};

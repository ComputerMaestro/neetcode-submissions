/*
When we select a position to place the queen then the diagonal positions to it and horizontal and veritical will become unavailable for that combination
Brute force would be to get all combinations and check which are valid 
for that we can put all queens in single line and keep moving the last one and the last two and so on to get all combinations 

Backtracking:
we need to eliminate the combinations when we reach a box which is not available and we will also have to mark the boxes when we select a box to mark the box unavaible corresponding to this selected position
we can do that easily by going over horizontally and vertically and diagonally, but for each select box doing this will increase the time complexity 
if possible we would want to make this O(1) operation

line : horizontal continuous square from start of one edge to the end of opposite edge 
veritical 
diagonal from top left to bottom right 
digonal from bottom right to top left 

for keeping track of these diagonals using four hashmaps 
each hashmap will have key of the starting square coordinates of each of line and value will be how many of queens are present in that line 
when we select a square to have a queen , we will have to update these four hashmaps 
in case we need to revert back a select square we will have to update again these four hashmaps 

for any square we can easily find the satrt square on its horiaontal line and veritcal line 
for diagonal top left to bottom right example: queen at (2,3) will have diagonal line start ()
*/

#include <unordered_map>

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        unordered_map<int, bool> cols;
        unordered_map<int, bool> positiveDiag;
        unordered_map<int, bool> negativeDiag;
        vector<vector<string>> res;
        vector<string> cur = vector<string>(n, string(n, '.'));
        backtrack(res, 0, 0, cur, cols, positiveDiag, negativeDiag);
        return res;
    }

    void backtrack(
        vector<vector<string>>& res,
        int row,
        int col,
        vector<string>& cur,
        unordered_map<int, bool>& cols,
        unordered_map<int, bool>& positiveDiag,
        unordered_map<int, bool>& negativeDiag
    ) {
        int n = cur.size();

        if (row == n) {
            res.push_back(cur);
            return;
        }

        if (col >= n) {
            return;
        }

        // Choice 1: Place a queen if safe
        if (!cols[col] &&
            !positiveDiag[row + col] &&
            !negativeDiag[row - col]) {

            cur[row][col] = 'Q';
            cols[col] = true;
            positiveDiag[row + col] = true;
            negativeDiag[row - col] = true;

            backtrack(res, row + 1, 0, cur,
                      cols, positiveDiag, negativeDiag);

            // Undo choice
            cur[row][col] = '.';
            cols[col] = false;
            positiveDiag[row + col] = false;
            negativeDiag[row - col] = false;
        }

        // Choice 2: Skip this cell and try next column
        // Always execute, even if current cell is unsafe
        backtrack(res, row, col + 1, cur,
                  cols, positiveDiag, negativeDiag);
    }
};

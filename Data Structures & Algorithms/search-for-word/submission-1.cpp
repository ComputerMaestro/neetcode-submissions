/*
Subsets : 
all the possible solutions using parsing all the possible combinatios and check when it meets word 

BackTracking: 
but since we have a way to elimite choices we can use backtracking 
we can start traversing the array from the top left corner and for each cell we will store a boolean value as well which will indicate that whether in this path we have used that cell or not 
For cell we can go in any of the four directions given the next cell is not already used. So in actual case we wil have only maimum of three choice (leaving the direction from which we can to current cell)
Also we will have to unmark any cell once we discard a path , we will only traverse a path until it is matching the letter sequecce of the word 

this will take O(n) space complexity
and the time complexty will be O(n * 3 ^ m) 
*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> marking(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != word[0]) {
                    continue;
                }
                marking[i][j] = true;
                if (backtracking(board, &marking, i, j-1, 1, word)) {
                    return true;
                }
                if (backtracking(board, &marking, i, j+1, 1, word)) {
                    return true;
                }
                if (backtracking(board, &marking, i-1, j, 1, word)) {
                    return true;
                }
                if (backtracking(board, &marking, i+1, j, 1, word)) {
                    return true;
                }
                marking[i][j] = false;
            }
        }
        return false;
    }

    bool backtracking(vector<vector<char>>& board, vector<vector<bool>>* marking, int row, int col, int matchIdx, string word) {
        if (matchIdx == word.size()) {
            return true;
        }
        if (row < 0 || row == board.size() || col < 0 || col == board[0].size() || board[row][col] != word[matchIdx] || (*marking)[row][col]) {
            return false;
        }
        (*marking)[row][col] = true;
        if (backtracking(board, marking, row, col-1, matchIdx + 1, word)) {
            return true;
        }
        if (backtracking(board, marking, row, col+1, matchIdx + 1, word)) {
            return true;
        }
        if (backtracking(board, marking, row-1, col, matchIdx + 1, word)) {
            return true;
        }
        if (backtracking(board, marking, row+1, col, matchIdx + 1, word)) {
            return true;
        }
        (*marking)[row][col] = false;
        return false;
    }
};

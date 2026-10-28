/*
we can do dfs traversal for each node and check whether it reaches an edge or not by substituting the value of the O with X and updating it back if edge countered on the way back. But in this case in wordst we might have to make a lot of choice

time complexity O(m * n * 4 ^ m * n)
space complexity will be O(m * n) for recursion

we can instead solve this starting from the edge cells with O and traverse connected lands to this and marke them with another keywords 
and this is done only remaining O will have to be replaced with Xs 
for that we will loop over all elements in matrix can change those new mark (N) to Os and O to Xs

time complexity will be O(m * n) since all the O will be travelled at max twice 
space complexity will be O(m * n) due to recursion or stack or queue

we will be using queue for bfs
*/

class Solution {
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() < 3 || board[0].size() < 3) {
            return;
        }
        queue<pair<int, int>> q;
        for(int r = 0; r < board.size(); r++) {
            if (r == 0 || r == board.size()-1) {
                for (int c = 0; c < board[0].size(); c++) {
                    if (board[r][c] == 'O') {
                        board[r][c] = 'N';
                        q.push({r, c});
                    }
                }
            } else {
                    if (board[r][0] == 'O') {
                        board[r][0] = 'N';
                        q.push({r, 0});
                    }
                    if (board[r][board[0].size()-1] == 'O') {
                        board[r][board[0].size()-1] = 'N';
                        q.push({r, board[0].size()-1});
                    }
            }
        }
        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            for (pair<int, int> d : directions) {
                int nr = p.first + d.first , nc = p.second + d.second;
                if (nr < 1 || nc < 1 || nr >= board.size()-1 || nc >= board[0].size()-1 || board[nr][nc] != 'O') {
                    continue;
                }
                board[nr][nc] = 'N';
                q.push({nr, nc});
            }
        }
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                } else if (board[r][c] == 'N') {
                    board[r][c] = 'O';
                }
            }
        }
        return;
    }
};

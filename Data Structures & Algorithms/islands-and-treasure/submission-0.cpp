class Solution {
    int inf = 2147483647;
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<tuple<int, int, int>> q;
        for(int row = 0; row < grid.size(); row++) {
            for(int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] != 0) {
                    continue;
                }
                q.push({row, col, 0});
                while(!q.empty()) {
                    tuple<int, int, int> t = q.front();
                    q.pop();
                    for(pair<int, int> d : directions) {
                        int nr = get<0>(t) + d.first, nc = get<1>(t) + d.second, nd = get<2>(t) + 1;
                        if (nr < 0 || nc < 0 || nr >= grid.size() || nc >= grid[0].size() || 
                        grid[nr][nc] <= nd) {
                            continue;
                        }
                        grid[nr][nc] = nd;
                        q.push({nr, nc, nd});
                    }
                }
            }
        }
    }
};

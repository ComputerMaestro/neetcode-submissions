class Solution {
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int maxArea = 0, area = 0;
        for(int row = 0; row < grid.size(); row++) {
            for(int col = 0; col < grid[0].size(); col++) {
                if (!grid[row][col]) {
                    continue;
                }
                area = 1;
                q.push({row, col});
                grid[row][col] = 0;
                while(!q.empty()) {
                    pair<int, int> p = q.front();
                    q.pop();
                    for (pair<int, int> d : directions) {
                        int nr = p.first + d.first, nc = p.second + d.second;
                        if (nr < 0 || nc < 0 || nr >= grid.size() || nc >= grid[0].size() || 
                        !grid[nr][nc]) {
                            continue;
                        }
                        area++;
                        grid[nr][nc] = 0;
                        q.push({nr, nc});
                    }
                }
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};

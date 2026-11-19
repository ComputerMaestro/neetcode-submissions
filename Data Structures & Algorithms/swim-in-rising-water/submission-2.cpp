/*
We can do DFS traversal for this and keep track of what level 
if nodes are level the then we can keep travelling them without increasing time but if come across a bigger square then increase the time to that level 

and keep tracking of smallest such possible level when returning the DFS recusion function and return teh smallest 
this will travel all nodes multiple times because each nodes has three options to move out of four

time complexity will be O(3^(n*m))
space complexity will be O(n*m) for keeping tracking of visited nodes

Dijkstra algo
since all weights are positive we can use this algo

only different is during edge relaxation we do not have time[u] + weight , instead if cur time[v] > time[u] then time[v] = max(grid[v], time[u])

time complexity O(n*mlog(e)) e = n-1 * m - 1 * 4
space cmpelxity will O(n*m) for tracking time per square
*/

class Solution {
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<vector<int>> times(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        times[0][0] = grid[0][0];
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        while(!pq.empty()) {
            vector<int> t = pq.top();
            pq.pop();
            int time = t[0], r = t[1], c = t[2];
            if (r == grid.size()-1 && c == grid[0].size()-1) {
                return time;
            }
            for(pair<int, int> d: directions) {
                int nr = r + d.first, nc = c + d.second;
                if (nr < 0 || nc < 0 || nr >= grid.size() || nc >= grid[0].size()) {
                    continue;
                }
                if(times[nr][nc] > time) {
                    times[nr][nc] = max(time, grid[nr][nc]);
                    pq.push({times[nr][nc], nr, nc});
                }
            }
        }
        return times[grid.size()-1][grid[0].size()-1];
    }
};

/*
For this we can use graph traversal , particularly the dfs 
as it is more suitable for this
to remember the visited points we would keep another grid of same dimensions, where 1 will mean the point in the grid is already visited 
this we are doing because for any island once we encounter a land this island we will traverse whole island since we are doing dfs and will mark all those as visited , so that another dfs path will merged with this . 
we will start traversals for all the nodes in the grid to check for all possibilities. 
return true from traversal function is island is possible from that node 
return false if already visited or island is not possible from that node

time complexity :
each node is travelled once , therefore time complexity will be O(N) n - number of nodes (row * col)

space complexity will be O(N) as we need a grid for this and another O(N) for the recursive stack trave
we can use either a stack or recursive solution. 

we can further reduce the space using bit manipulation instead of using a 2d grid
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                count += dfs(grid, visited, i, j); 
            }
        }
        return count;
    }

    bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col) {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || visited[row][col] || grid[row][col] == '0') {
            return false;
        }
        visited[row][col] = true;
        dfs(grid, visited, row + 1, col);
        dfs(grid, visited, row, col + 1);
        dfs(grid, visited, row - 1, col);
        dfs(grid, visited, row, col - 1);
        return true;
    }
};

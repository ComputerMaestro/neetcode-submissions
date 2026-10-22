/*
Here we can start traversing the map starting from every point in grid. And check if an island exists. if it exists keep traversing all the island grid points and mark them visited (by making the grid with 1 to zero) and also return number of travelled points which will be area . 

We can go this recursive , for every node we have four directions 
up 
down 
left 
right 

if island exist from that node them return the area of that island 
and we can the end after finishing all grid points we can track the maximum area 
and return it 

time complexity : O(m * n) m => no of rows in grid , n => no of columns in the map grid
space compleixty : O(m * n) because we need maximum recursive calls equal to the number of points in grid which is m * n
*/

func maxAreaOfIsland(grid [][]int) int {
	var dfs func(int, int) int
	dfs = func(row, col int) int {
		if row < 0 || col < 0 || row >= len(grid) || col >= len(grid[0]) || grid[row][col] == 0 {
			return 0
		}
		grid[row][col] = 0
		return 1 + dfs(row, col + 1) + dfs(row, col - 1) + dfs(row + 1, col) + dfs(row - 1, col)
	}
	maxArea := 0
	for r, _ := range grid {
		for c, _ := range grid[r] {
			maxArea = max(maxArea, dfs(r, c))
		}
	}
	return maxArea
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

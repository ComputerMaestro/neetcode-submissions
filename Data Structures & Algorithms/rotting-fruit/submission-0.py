"""
For getting minimum number of minutes we need to find the fresh fruits whose distance from its nearest rotten fruit.
maximum of minimum distance from a rottne for any fresh fruit 

if any fresh fruit cannot be reached from any rotten fruit then it is not possible 

for this we can start a traversal from rotten fruits and store a distance for all the fresh fruits from the rotten and we need to keep tracking the maximum value of the fresh fruits to its nearest rotten fruit
when we move to a next fresh fruit we need to check it already has a value less then cur value + 1

once traversal for all the rotten fruits are done
we return the max value we have been tracking

in this way each node will have to be traversed at max number of times as the number of rotten fruits in the matrix 
time complexity will be O(m * n * r)
space complexity will be O(1)
since we just need to track the max value for that we will just need few extra variable to keep track of visited values we can update the grid itself
"""

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        q = []
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        for row, _ in enumerate(grid):
            for col, v in enumerate(grid[row]):
                if v == 2:
                    grid[row][col] = -2
                    q.append((row, col, 0))
                elif v == 1:
                    grid[row][col] = -1
                elif v == 0:
                    grid[row][col] = -3
        
        while len(q) != 0:
            r, c, d = q.pop(0)
            for direction in directions:
                nr, nc, nd = r + direction[0], c + direction[1], d + 1
                if nr < 0 or nc < 0 or nr >= len(grid) or nc >= len(grid[0]) or grid[nr][nc] < -1:
                    continue
                if (grid[nr][nc] == -1) or (grid[nr][nc] > 0 and grid[nr][nc] > nd):
                    grid[nr][nc] = nd
                    q.append((nr, nc, nd))
        
        maxMinutes = 0
        for r in grid:
            for c in r:
                if c == -1:
                    return -1
                else:
                    maxMinutes = max(maxMinutes, c)
        return maxMinutes

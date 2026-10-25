"""
For this straight forward way would be to find longest increasing path for each matrix cell 
in this case we also do not need to track the path , because each path will be traverse from smaller to larger digits and therefore we cannot go back to smaller and that's no cell will be repeated in a path

but this will take 
time complexity of O((m * n)^2)
space complexity of O(1) for tracking max value

to improve time we can store the longest increasing path whenever we cross that node and come back in the recursion or stack 

and when we return , update the value for that node in a 2d array for later usage
time complexity will be O(m * n) as each node will be processed once
space compelxit will O(m * n) extra dp memoization space and recursion
"""
class Solution:
    directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        dp = [[-1] * len(matrix[0]) for _ in matrix]
        m = -1
        for r, _ in enumerate(matrix):
            for c, _ in enumerate(matrix[0]):
                m = max(m, Solution.dfs(matrix, dp, r, c, -1))
        return m
    
    @classmethod
    def dfs(cls, matrix: List[List[int]], dp: List[List[int]], row: int, col: int, last: int) -> int:
        if row < 0 or col < 0 or row >= len(matrix) or col >= len(matrix[0]) or matrix[row][col] <= last:
            return 0
        if dp[row][col] != -1:
            return dp[row][col]

        for d in cls.directions:
            dp[row][col] = max(dp[row][col], Solution.dfs(matrix, dp, row + d[0], col + d[1], matrix[row][col]))
        dp[row][col] += 1
        return dp[row][col]
        
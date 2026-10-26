"""
We can use backtracking for check all the possible combinations and count 
but that will be too expensive and we will have to maintaing distinct values as well 
to maintain distinct solution only match the letters on the right with the current letter of the cat 

instead we can use dp with 2d 
for index i in s how many possible combinations subsequences which are equal to substring of t starting index j 

we can use tabulation method 
we the find the solutions of from the end of both the strings to reach the final string lengths

what will give 
time complexity of O(m * n) m length of s and n length of t
space complexity of O(m * n) to remeber the values 
"""
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        dp = [[0] * (len(t)+1) for _ in range(len(s)+1)]
        for i in range(len(s), -1, -1):
            dp[i][len(t)] = 1
        for i in range(len(s)-1, -1, -1):
            for j in range(len(t)-1, -1, -1):
                if len(s) - i >= len(t) - j:
                    if s[i] == t[j]:
                        dp[i][j] = dp[i+1][j+1] + dp[i+1][j]
                    else:
                        dp[i][j] = dp[i+1][j]
        return dp[0][0]
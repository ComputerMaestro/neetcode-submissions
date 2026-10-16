/*
Here we will have to explore all combinations summed upto the target value 
if target cannot be reached then return -1
Backtracking:
since we can eliminate any combination once it reaches or crosses target 
we can do this recursively 
time compelxity will O(n^(t/m))
space compleixty will O(t/m) for recursive calls 
that is bcause for every choice we have the same number available again 

Here we can also store outcome of a explored combination which we can use for overlapping sub combiantions 
Dyamic programming

time complexity will be O(n^(t/m)/2)
space compleixty will O(n2)

also we need to keep track of minim, because we can haVe multiple combinations reaching target
memoize: from a particular index what is the minimum number of coins needed to reach a target (not the fial target, but a number between 1 to target)
*/


func coinChange(coins []int, amount int) int {
	sort.Sort(sort.Reverse(sort.IntSlice(coins)))
	memo := make([][]int, len(coins))

    // 2. Allocate each inner slice (columns) and fill with the default value
    for i := range memo {
        memo[i] = make([]int, amount+1)
        for j := range memo[i] {
            memo[i][j] = -2
        }
    }
	var dp func(*[]int, *[][]int, int, int) int
	dp = func(coins *[]int, memo *[][]int, target, i int) int {
		if target == 0 {
			return 0
		}
		if i >= len(*coins) || target < 0 {
			return -1
		}
		if (*memo)[i][target] != -2 {
			return (*memo)[i][target]
		}
		c := dp(coins, memo, target - (*coins)[i], i)
		if c != -1 {
			c += 1
		}
		(*memo)[i][target] = c
		n := dp(coins, memo, target, i+1)
		if (*memo)[i][target] == -1 {
			(*memo)[i][target] = n
		} else {
			if n != -1 {
				(*memo)[i][target] = min((*memo)[i][target], n)
			}
		}
		return (*memo)[i][target]
	}
	return dp(&coins, &memo, amount, 0)
}

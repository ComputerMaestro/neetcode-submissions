/*
Brute force:
Loop over the nums and find all possible combinations but keeping tracking of negatives 
we will have to loop over 
1 negative 
2 neatives 
3 negatives 
and so on up to n negatives 
to find all combinations 

time compelxity will be O(2^n)

or we can use backtracking but that will also take same time complexity will 

to improve that we can use memoization 

DP method:
we can store the 
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int s = 0;
        for (int num: nums) {
            s += num;
        }
        vector<vector<int>> memo(2*s+1, vector<int>(nums.size(), -1));
        return dp(nums, memo, s, target, 0, 0);
    }

    int dp(vector<int>& nums, vector<vector<int>>& memo, int maxSum, int target, int i, int sum) {
        if (i == nums.size()) {
            if (sum == target) {
                return 1;
            }
            return 0;
        }
        if (memo[sum + maxSum][i] != -1) {
            return memo[sum + maxSum][i];
        }
        memo[sum + maxSum][i] = dp(nums, memo, maxSum, target, i+1, sum + nums[i]) + dp(nums, memo, maxSum, target, i+1, sum - nums[i]);
        return memo[sum + maxSum][i];
    }
};

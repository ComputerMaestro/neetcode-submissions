/*
here we will have to find the all combinations in which we can rob the houses along with their total and return the maximum of them 

We can use backtracking to find all the combinations by incorporating the rule that we cannot rob the next house and keep tracking the maximum 
but in this case for a current house we just need to find the maximum can get in subsequence houses 
basically we are making the problem shorter 
therefore, we can use dynamic programming here , by storing the maximum for a set of houses and build the bigger set which depends on this set using this maximum value 

this tracking can be done using a simple array or vector of same length as the nums or we can use a hashmap which will contain the maximum value possible for each index in nums from that index to the end of nums 
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> maxs(nums.size(), -1);
        return max(dp(nums, maxs, 0), dp(nums, maxs, 1));
    }

    int dp(vector<int>& nums, vector<int>& maxs, int i) {
        if (i >= nums.size()) {
            return 0;
        }
        if (maxs[i] != -1) {
            return maxs[i];
        }
        maxs[i] = max(dp(nums, maxs, i + 2) + nums[i], dp(nums, maxs, i + 3) + nums[i]);
        return maxs[i];
    }
};

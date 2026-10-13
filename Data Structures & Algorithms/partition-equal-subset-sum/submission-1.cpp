/*
Brute force: 
we can just make all the combinations and compare the sums and return if ever matched
for that we need to only select the elements for the subset 1 and subset 2 is automatically the remaining elemetns and we can track the sums for both by adding new element fro subset 2 to subset 1 and subtracting from subset 2 sum 

time complexity O(2^n) since we try ing all the combinations 
space complexity O(n) since we will need to track waht all elements are selected in the current subset 1



*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int num : nums) {
            total += num;
        }
        if (total % 2 == 1) {
            return false;
        }
        vector<int> s;
        return rec(nums, s, 0, 0, total);
    }

    bool rec(vector<int>& nums, vector<int>& set1, int i, int sum1, int sum2) {
        if (sum1 == sum2) {
            return true;
        }

        if (i >= nums.size()) {
            return false;
        }

        set1.push_back(i);
        sum1 += nums[i];
        sum2 -= nums[i];
        if (rec(nums, set1, i+1, sum1, sum2)) {
            return true;
        }
        set1.pop_back();
        sum1 -= nums[i];
        sum2 += nums[i];
        return rec(nums, set1, i+1, sum1, sum2);
    }
};

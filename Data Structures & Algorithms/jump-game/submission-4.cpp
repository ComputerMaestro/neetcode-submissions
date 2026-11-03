/*
we can for all answer using backtracking 
but that will take 
time comrplexity of O(2^n) 
space complexity  of O(n) for recursion

if we can keep moving forward we can reach the last element 
for that
for current index we check the max jump and get the max index we can reach and check all values in between current index upto this max index and get the max value of jump 
using that if can get out of the current max jump value then we can move forward otherwise we cannot and therefore cannot reach the last value and return false 

time complexity will O(n) as each elements is read max once
space complexit will O(1) for few tracking variable needed
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() < 2) {
            return true;
        }
        int i = 0;
        while(i < nums.size()) {
            if (nums[i] == 0 && i < nums.size()-1) {
                return false;
            }
            if (nums.size()-1 <= i + nums[i]) {
                return true;
            }
            int m = -1;
            int maxIdx = -1;
            for (int j = i+1; j <= i + nums[i]; j++) {
                if (j + nums[j] >= nums.size()) {
                    return true;
                }
                if (maxIdx < j + nums[j]) {
                    m = j;
                    maxIdx = j + nums[j];
                }
            }
            if (maxIdx <= i + nums[i]) {
                return false;
            }
            i = m;
        }
        return true;
    }
};

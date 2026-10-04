class Solution {
public:
    int search(vector<int>& nums, int target) {
        int startIdx = 0, endIdx = nums.size() - 1;
        while(endIdx - startIdx >= 1) {
            int mid = (endIdx - startIdx) / 2;
            if (nums[startIdx + mid] >= target) {
                endIdx = startIdx + mid;
            } else {
                startIdx = startIdx + mid + 1;
            }
        }
        if (nums[startIdx] == target) {
            return startIdx;
        }
        return -1;
    }
};

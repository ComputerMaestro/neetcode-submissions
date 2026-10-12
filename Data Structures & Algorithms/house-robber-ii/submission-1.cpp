/*
So since the houses are now in circular order , whether we are selecting first house will affect the selection choice of the last house in the list

Dynamic programming:
memoization 
we will have to keep track whether we have selected first or not 
for that we just pass a boolean representing selection of first house 
if it is true , then last house cannot be chosen 
if false, we can include that last house as well
*/


class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int temp1 = 0;
        int temp2 = 0;
        int max1 = 0;
        int max2 = 0;
        int last1 = 0;
        int last2 = 0;
        for(int i = 0; i < nums.size(); i++) {
            if (i > 0) {
                max2 = max(last2, temp2 + nums[i]);
                temp2 = last2;
                last2 = max2;
            }
            if (i < nums.size()-1) {
                max1 = max(last1, temp1 + nums[i]);
                temp1 = last1;
                last1 = max1;
            }
        }   
        return max(last1, last2);
    }
};

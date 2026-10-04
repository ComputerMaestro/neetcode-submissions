/*
Using Bit manipulation:
We can use interger bits ot store the information regarding presence of a number
for max n = 10000 we will need:
    10000 bits for each integer => 10000 / 64 => 157 integers max (as int64 is 8 bytes)

    we will initialize an array of 157 and then use it 
    or we can also calculate the number of int64 needed for the calculation using nums.length

    for will loop over the nums and keep setting the bits in the array int which corresponds to that particular number then if we come across an already set bit that means that num has duplicates

    this way max bytes is 157 which means O(1) space complexity and the time complexity is O(n)
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, bool> numToFreq;
        for(int i = 0; i < nums.size(); i++) {
            if (numToFreq[nums[i]]) {
                return nums[i];
            } else {
                numToFreq[nums[i]] = true;
            }
        }
        return 0;
    }
};

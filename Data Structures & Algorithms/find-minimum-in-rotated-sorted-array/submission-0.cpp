/*
The brute force Method
Simply traverse the array and find the first element which is smaller than its previous element 
if can't find then that means the first element is the minium element

Binary Search Method:
If anything is partially rotated then last element will be smaller than the first element and if fully rotated only then the first elements will be less than last element 

we need a condition to move towards the minimum element in binary search 
that condition is comparing with last element 
if the cur element is larger than the last element -> we are on the part of array which is the right side of minimum element -> then elements came before minimu mafter rotation because these are bigger than last elemnt and minimum element either equal or larger than last element therfore any larger element is coming before the minimum element and we need to move to right 
if the cur element is smaller than the last element -> that means we are either on minimum element or on element which comes after the minimum element in array so to move towards the minimum element we need to go towards left side. 

during binary search we have two conditions 
for example
1 2 3 4 5 6 7 8 
7 8 1 2 | 3 4 5 6 --> 2 is less than 6 , move left 
3 4 5 6 | 7 8 1 2  --> 6 is m more last element (2) ,  move right
*/

class Solution {
public:
    int findMin(vector<int> &nums) {
        int startIdx = 0, endIdx = nums.size() - 1;
        int lastNum = nums[nums.size() - 1];
        while(startIdx < endIdx) {
            int mid = startIdx + (endIdx - startIdx) / 2;
            if (nums[mid] < lastNum) {
                endIdx = mid;
            } else if (nums[mid] > lastNum) {
                startIdx = mid + 1;
            }
        }
        return nums[startIdx];
    }
};

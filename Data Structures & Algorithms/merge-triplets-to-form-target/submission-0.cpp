/*
To get the target triplet 
important thing to note is that any triplet whose any element is greater than element in same position in target than that triplet is definetly not useful to achieve target 
To reach target the triplets whose all elements are either equal or less than the target elements can be used. 
Another important part is that for elements in target there should at least one such triplet whose atleast one elments is equal to one of target element and others should be less than or equal to other two and this should be true for all the target elemnts , if not than target cannot be achieve using the given max rule 

because using max rule to reach target , eneed the target x y z value in teh triplets which we are going to use at least once 

bool isX,  isY, isZ (show whether x , y or z can be reached )
for each triplet
    if ai > x || bi > y || ci > x : continue
    if ai == x : isX = true
    if bi == y : isY = true
    if ci == z : isZ = true
    if isX and isY and isZ are aqll true then return true

return false 

time complexity will be O(n) n is number of triplets 
space complexity will be O(1) since only few extra variables are used
*/

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool isX = false, isY = false, isZ = false;
        int ai, bi, ci, x = target[0], y = target[1], z = target[2];
        for(vector<int> triplet: triplets) {
            ai = triplet[0], bi = triplet[1], ci = triplet[2];
            if (ai > x || bi > y || ci > z) {
                continue;
            }
            if (ai == x) {
                isX = true;
            }
            if (bi == y) {
                isY = true;
            }
            if (ci == z) {
                isZ = true;
            }
            if (isX && isY && isZ) {
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int startIdx = 0, endIdx = matrix.size()-1;
        int rowSize = matrix[0].size();
        while(startIdx < endIdx) {
            int mid = startIdx + (endIdx - startIdx) / 2;
            if (matrix[mid][rowSize-1] >= target) {
                endIdx = mid;
            } else {
                startIdx = mid + 1;
            }
        }
        if (startIdx == endIdx) {
            int rStartIdx = 0, rEndIdx = rowSize - 1;
            while(rStartIdx < rEndIdx) {
                int rm = rStartIdx + (rEndIdx - rStartIdx) / 2;
                if(matrix[startIdx][rm] >= target) {
                    rEndIdx = rm;
                } else {
                    rStartIdx = rm + 1;
                }
            }
            if (rStartIdx == rEndIdx && matrix[startIdx][rStartIdx] == target) {
                return true;
            }
        }
        return false;
    }
};

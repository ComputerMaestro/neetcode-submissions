
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> finalSS = {vector<int>()};
        for(int i = 1; i <= nums.size(); i++) {
            vector<vector<int>> ss = findSubsetsOfLength(nums, {}, 0, i);
            finalSS.insert(finalSS.end(), ss.begin(), ss.end());
        }
        return finalSS;
    }

    vector<vector<int>> findSubsetsOfLength(vector<int>& nums, vector<int> fixed, int sIdx, int l) {
        vector<int> s;
        vector<vector<int>> curSS;
        for(int i = sIdx; i <= nums.size()-l; i++) {
            if (l - 1 > 0) {
                s = fixed;
                s.push_back(nums[i]);
                vector<vector<int>> ss = findSubsetsOfLength(nums, s, i+1, l-1);
                curSS.insert(curSS.end(), ss.begin(), ss.end());
            } else {
                s = fixed;
                s.push_back(nums[i]);
                curSS.push_back(s);
            }
        }
        return curSS;
    }
};

/*
the intervals are already sorted so we need to just find the range of intervals which will overlap with this new interval to check that 
it is important to note that the final interval after inserting will start from etierh the start of new internval start or from another interval which have end_i >= start_new , from here the interval will start merging because any further interval will keep overlapping with this new interval until 
end_new < start_i (i is any other interval after the starting interval )


time complexity will be O(n)
space complexity will O(n) for extra array for results
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<int> curInterval = newInterval;
        vector<vector<int>> results;
        bool insert = false;
        for(int i = 0; i < intervals.size(); i++) {
            if (newInterval[1] < intervals[i][0]) {
                if (!insert) {
                    results.push_back(curInterval);
                    insert = true;
                    copy(intervals.begin() + i, intervals.end(), back_inserter(results));
                    return results;
                }
            } else {
                curInterval[1] = max(curInterval[1], intervals[i][1]);
            }
            if (newInterval[0] <= intervals[i][1]) {
                curInterval[0] = min(curInterval[0], intervals[i][0]);
            } else {
                results.push_back(intervals[i]);
            }
        }
        if (!insert) {
            results.push_back(curInterval);
            insert = true;
        }
        return results;
    }
};

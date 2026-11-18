class Solution {
public:
    int climbStairs(int n) {
        if (n < 2) {
            return 1;
        }
        int waysLastSec = 1;
        int waysLast = 1;
        int cur = 0;
        for (int i = 2; i <= n; i++) {
            cur = waysLastSec + waysLast;
            waysLastSec = waysLast;
            waysLast = cur;
        }
        return cur;
    }
};

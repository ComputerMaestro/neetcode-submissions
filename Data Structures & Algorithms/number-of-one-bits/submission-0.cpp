class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ones = 0;
        for (int i = 0; i < 32; i++) {
            ones += (1 & n);
            n = n >> 1;
        }
        return ones;
    }
};

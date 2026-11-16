/*
Since we need to rearrange , we can first sort them to simply it
it will take O(nlogn) time complexity 
we can use backtracking to check if it is possible to get rearrange in given group size 
time complexity will be O(n*2^n) for all combinations

Greedy approach:
a new sequence start when there is extra hand left for any value 
so in this sorted hands array 
we can start a hand sequeuence when we encounter any extra hand
for that we need frequence of every value 

ex
hand = 1, 2, 4, 2, 3, 5, 3, 4, groupsize = 4
sorted = 1, 2, 2, 3, 3, 4, 4, 5
freqmap => 1 -> 1 , 2 -> 2, 3 -> 2, 4 -> 2, 5 -> 1
so the first sequence start from 1 which will end on 4 (so we reduce freq of each number 1 , 2, 3, 4 by 1) 
now second sequence will start from 2 because (one 2 hand will be left after including one in the first sequence)

we can do this and check if any where during subtraction if we encounter zero , then that means the sequence can make the size equal to group size and return false 
time complexity will be O(n * g)
space complexity will O(n)

to further simplify this we need to remove this groupsize subtraction for each hand
for that we can keep track of number of sequence running current and end of each sequence 
using a variable and an array

we will need freq of each distinct hand and sorted array of this distinct hands 
and a sequeunce count variable 
for each value in sorted distinct hand array
 - if seqCount > freq(handIdx) + endSeq[handIdx]
    return false
 - if 

 time compelxity will be O(n)
 space complexity will be O(n) for freqmap and ending array
*/
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int, int> freqMap;
        vector<int> sorted;
        for (int h: hand) {
            freqMap[h]++;
            auto i = lower_bound(sorted.begin(), sorted.end(), h);
            if (i == sorted.end() || *i != h) {
                sorted.insert(i, h);
            }
        }

        vector<int> seqEnd(sorted.size());
        int s = 0;
        for (int i = 0; i < sorted.size(); i++) {
            if (s > freqMap[sorted[i]]) {
                return false;
            }
            if (freqMap[sorted[i]] - s > 0) {
                if (i + groupSize - 1 >= sorted.size()) {
                    return false;
                } else {
                    if ((freqMap[sorted[i + groupSize - 1]] < seqEnd[i + groupSize - 1] + freqMap[sorted[i]] - s) || (sorted[i] + groupSize - 1 != sorted[i + groupSize - 1])) {
                        return false;   
                    }
                    seqEnd[i + groupSize - 1] += freqMap[sorted[i]] - s;
                }
            }
            s = s + freqMap[sorted[i]] - s - seqEnd[i];
        }
        return true;
    }
};

/*
if we know the last occurance of each letter we can go over the array and get the substrings in O(n) time using:
we start traversing the array 
for each letter in array 
if curLetter end occurance if cur index then substring end will be one, and push length one to results array
if curLetter end occurne if not cur index then substring end will be last occurennce index - cur index + 1
if substring length 
*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26, -1);
        for(int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        vector<int> substrings;
        for (int i = 0, j = -1, curEnd = -1; i < s.size(); i++) {
            if (last[s[i] - 'a'] > curEnd) {
                curEnd = last[s[i]-'a'];
            }
            if (i == curEnd) {
                substrings.push_back(i - j);
                j = i;
            }
        }
        return substrings;
    }
};

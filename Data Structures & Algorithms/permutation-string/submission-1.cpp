/*
length of s1 is m
length of s2 is n

Sorting Solution:
We can first sort the s1 string in O(mlogm) time complexity
Then take the first m elements in the s2 string and sort that => O(mlogm) time complexity
Now for the permutation the length of the sub string will be same as m so we maintain this window of first m letters from s2 
and keep inserting one next element and removing first element with maintaing the sorted order using insertion sort kind of algo which for each will max take => O(m) time 
And with each sub string we will keep checking the s1 and return true if matched 
This sorting will be done for each element in s2 therefore the time complexity will be O(mn) 

And since the maximum ordre of growth is O(mn) as n will be equal for greater than m , because if not return false


Sliding window Optimized solution:
Maintain a hashmap from key as letter in the string in a windows length of m and value is frequency of occurence (beccaus there could be duplicate letters)
We maintain a window and for that window this hashmap will be updated as the window moves forward on s2 
and also we will have to maintain a matching count variable which will show how many of current window letters are matching with s1 and once s1.size() is equal tot he matching count, we will return true
O(m) space complexity
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) {
            return false;
        }
        unordered_map<char, int> matchMap;
        unordered_map<char, bool> presentMap;
        int matchCount = 0;
        for(int i = 0; i < s1.size(); i++) {
            presentMap[s1[i]] = true;
            matchMap[s1[i]]++;
        }
        for(int i = 0; i < s1.size(); i++) {
            if(presentMap[s2[i]]) {
                if (matchMap[s2[i]]) {
                    matchCount++;
                }
                matchMap[s2[i]]--;
            }
        }
        if (s1.size() == matchCount) {
            return true;
        } 
        for(int i = s1.size(); i < s2.size(); i++) {
            if (presentMap[s2[i-s1.size()]]) {
                matchMap[s2[i-s1.size()]]++;
                if (matchMap[s2[i-s1.size()]]) {
                    matchCount--;
                }
            }
            if (presentMap[s2[i]]) {
                if (matchMap[s2[i]]) {
                    matchCount++;
                }
                matchMap[s2[i]]--;
            }
            if (s1.size() == matchCount) {
                return true;
            } 
        }
        return false;
    }
};

/*

Brute force solution:
to run loop for all charater in string
for each character if the character is equal to previous character then skip 
for each character run a nested loop for k iterations 
where the count increase only if the elements if not equal to current element 
at the last element of this internal loop we need to check next element as well until we get same alphabet as the cur alphabet in main we will keep going forward even after k elements 
and after this internal loop get the length from the last element at which this stopped and store the value in longest variable if it bigger then current longest value 

this way we can get the longest length 
the time taken here will be O(n*k) time complexity 
becase for each element we will have ot check at least k elements and also even if there are duplicate we compensating same time when we skip those duplicates 





Slinding window solution
We use the same approach by looping for each element in the string 
again skip same elements if equal to previous element in the loop
We also maintina a hash map which contains the element in the current window and their frequencies
For an alphabet we check in map how many duplicate are present in the current window 
we loop over from teh last element of the window by those many elements forward and this number only decreases when the element if not equal to cur alhabet 
once this is zero keeping going forward until the alphabet is same as the main loop current alphabet 
for duplicate elements which will keep coming in multiple loops will be compensated when we skip same adjacent alphabets 
after these internal loops finishes we calculate differnt of last index and the cur main alphabet index and update the longest variable if required 

return the longest 

time complexity here will be O(n) bcause the dupliate which we calculate multiple times will also be skipped when there turns comes 
space will be O(1) beccause we will maintain the hashmap of 26 elements at max in worst case. 



*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.size() <= 1) {
            return s.size();
        }
        unordered_map<char, int> charToFreq;
        int r = 0, l = 0, maxFreq = 1;
        while(r < s.size()) {
            if(charToFreq.find(s[r]) == charToFreq.end()) {
                charToFreq[s[r]] = 1;
            } else {
                charToFreq[s[r]]++;
            }
            if (maxFreq < charToFreq[s[r]]) {
                maxFreq = charToFreq[s[r]];
            }
            if (r - l + 1 - maxFreq > k) {
                charToFreq[s[l]]--;
                l++;
            }
            r++;
        }
        return r - l ;
    }
};

/*
Brute Force Method:

run loop for each character in string 
in each iteration we will check all the possible sub array starting from current character
we can track the occurence of a characterin a sub array using hash maps 

number of instructions in each iteration
n-1,n-2 n-2 n-3 .... 2 1 => O(n2) time complexity
and the space complexity will be O(1) because we will be using a single hashmap and that hashmap can only have maximum of number of ASCII characters possible , which is 256 

SLIDING WINDOW ALGO:

we will start building our sub array window and also keep a hashmap which will store key as the cahracter and the value will its index in the given string s
once we encounter a character which is duplicate and already present in the hashmap 
we will update the max length if applicable
we loop from start index of window to the index found in the hashmap of this current character and 
	in each iteration delete the key or set the key to -1 in the hashmap
the window will be shorten and the starting of the window will be set to the next index of the index for which the duplicate character is found. 

In above example:
at index 7 , when we encounter the second 'a' , we will set the starting index of window to 4 at the 'b' which is next character after the 'a' 

Also, in this case since we are only traversing the s only once , then the time complexity will beb O(n)
where n is number of characters in the string
*/

func lengthOfLongestSubstring(s string) int {
	curStart := 0
	curEnd := 0
	maxLength := 0
	charMap := map[rune]int{}

	for ; curEnd < len(s) && curStart <= curEnd; curEnd++ {
		curChar := rune(s[curEnd])
		if idx, ok := charMap[curChar]; idx != -1 && ok {
			if maxLength < curEnd - curStart {
				maxLength = curEnd - curStart
			}
			for ; curStart <= idx; curStart++ {
				c := rune(s[curStart])
				charMap[c] = -1
			}
		}
		charMap[curChar] = curEnd
	}
	if curEnd - curStart > maxLength {
		maxLength = curEnd - curStart
	}
	return maxLength
}

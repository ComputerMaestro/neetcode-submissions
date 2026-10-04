/*

Encoding is like this 
- all the letter in every string will be converted to their corresponding unicode numbers 
- all the letters in a string will be separated by "+" delimiter
- all the strings in the encoded will be separate by "|" delimiter 

Example:
["", "hello", "world"]
after encoding: :|123+123+345+345+456|123+123+123+123+123:

For decoding 
if string received for decoding is emtpy without any colons as well, then that means the list was empty
first check the string between two colons 
split string between colons by "|" delimiter , we will get list of encoded strings 
for each encoded string 
    split it again using "+" delimiter and that will give list of unicodes 
    now just convertd this list of unicode back to the string

return the decoded list of strings 

*/

// const (
//     STRING_DELIMITER = "|"
//     LETTER_DELIMITER = "+"
//     LIST_INDICATOR = ":"
// )

// type Solution struct{}

// func (s *Solution) Encode(strs []string) string {
//     if len(strs) == 0 {
//         return ""
//     }
//     encodedStrings := []string{}
//     for _, str := range strs {
//         unicodes := []string{}
//         for _, r := range []rune(str) {
//             unicodes = append(unicodes, fmt.Sprintf("%d", r))
//         }
//         encodedStrings = append(encodedStrings, strings.Join(unicodes, LETTER_DELIMITER))
//     }
//     return LIST_INDICATOR+strings.Join(encodedStrings, STRING_DELIMITER)+LIST_INDICATOR
// }

// func (s *Solution) Decode(encoded string) []string {
//     if encoded == "" || len(encoded) < 2 {
//         return []string{}
//     }
//     if encoded[0] != ':' || encoded[len(encoded)-1] != ':' {
//         return []string{}
//     }
//     decodedStrings := []string{}
//     encodedStrs := strings.Split(encoded[1:len(encoded)-1], STRING_DELIMITER)
//     for _, encodedStr := range encodedStrs {
//         decodedStr := ""
//         for _, unicodeStr := range strings.Split(encodedStr, LETTER_DELIMITER) {
//             unicode, _ := strconv.Atoi(unicodeStr)
//             decodedStr = decodedStr + fmt.Sprintf("%c", rune(unicode))
//         }
//         decodedStrings = append(decodedStrings, decodedStr)
//     }
//     return decodedStrings
// }

type Solution struct{}

func (s *Solution) Encode(strs []string) string {
	if len(strs) == 0 {
		return ""
	}
	var sizes []string
	for _, str := range strs {
		sizes = append(sizes, strconv.Itoa(len(str)))
	}
	return strings.Join(sizes, ",") + "#" + strings.Join(strs, "")
}

func (s *Solution) Decode(encoded string) []string {
	if encoded == "" {
		return []string{}
	}
	parts := strings.SplitN(encoded, "#", 2)
	sizes := strings.Split(parts[0], ",")
	var res []string
	i := 0
	for _, sz := range sizes {
		if sz == "" {
			continue
		}
		length, _ := strconv.Atoi(sz)
		res = append(res, parts[1][i:i+length])
		i += length
	}
	return res
}

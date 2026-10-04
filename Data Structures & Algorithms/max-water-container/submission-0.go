/*
Brute Force Method:
To calculate areas of all the pairs of heights possible and return the max
That will give us => O(n2) time complexity

Using Two pointer Method: 
initialize
startPillarPointer => to the first height
endPillarPointer => to the last height

calculate the area between these heights and that will be current max area

initially we are on the maximum length possible for the container 
IMPORTANT: To further increase the area of the container 
the minimum of the two heights should increase when we decrease the container length 

for that we will have to move the pointer with shorter height of the two until we get pillar with more height
Then calculate area again and repeat the process until startPointer is one less than endPointer


*/

func maxArea(heights []int) int {
	startPointer := 0
	endPointer := len(heights)-1
	
	maxArea := 0
	for startPointer < endPointer {
		curArea := min(heights[startPointer], heights[endPointer]) * (endPointer - startPointer)
		if maxArea < curArea {
			maxArea = curArea
		}
		if heights[startPointer] < heights[endPointer] {
			startPointer++
		} else if heights[startPointer] > heights[endPointer] {
			endPointer--
		} else if heights[startPointer] == heights[endPointer] {
			startPointer++
			endPointer--
		}
	}
	return maxArea
}

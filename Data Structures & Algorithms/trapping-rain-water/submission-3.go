/*
Two Pointer Method:
In this case, we will initialize the a and b pointer at the first height in the heights array
then we will start increasing the pointer b and we will keep checking the difference in height ha and hb
if ha - hb is positive that means their is a decrease in height and only in that case the water can be trapped , until the heights is increasing their is not gap for the water to be trapped
and so we will add this difference to the current area in which water is trapped because this 
(ha - hb ) * 1 is aread of water trapped in the increament 

if ha - hb is zero or negative, in that case the pointers will both keep increasing 
and add the current area to the total area and make current area back to zero

when the pointer b reaches the end of array , then
if height[end] < height[a] 
	we need to decrease the area which we added above height[end]
	another pointer, names l (last - compartment)
	for that we need to loop from s to end again , l = s to end
		where for eahc iteration curArea = curArea - (min(height[a]-height[b], height[a]-height[l]))

return the total area where water is trapped 

in this case sine we are just moving one at a time from start to the end of the heights 
time complexity will be O(n)
and since we are only using two extra variable for pointers, space complexity will be O(1)
*/

func trap(height []int) int {
	s := 0
	e := 0

	trappedWaterArea := 0
	curTrappedWaterArea := 0
	for ;e < len(height); e++ {
		if height[s] - height[e] > 0 {
			curTrappedWaterArea += height[s] - height[e]
		} else {
			trappedWaterArea += curTrappedWaterArea
			curTrappedWaterArea = 0
			s = e
		}
	}
	if s < len(height) - 1 {
		curTrappedWaterArea = 0
		e = len(height) - 1
		m := len(height) - 1
		for ; m >= s; m-- {
			if height[e] > height[m] {
				curTrappedWaterArea += height[e] - height[m]
			} else {
				trappedWaterArea += curTrappedWaterArea
				curTrappedWaterArea = 0
				e = m
			}
		}
	}
	return trappedWaterArea
}

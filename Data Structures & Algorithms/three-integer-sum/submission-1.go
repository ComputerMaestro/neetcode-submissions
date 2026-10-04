/*
Sorting and Two Pointer Method:

nums[i] + nums[j] + nums[k] = 0
nums[i] + nums[j] = -nums[k]
target => -nums[k]
where nums[k] is all the numbers

First , sort the array => O(nlogn) time complexity
For each element find the sum of any other two elements equal to the negative the current element in that sorted array using two pointer method

two pointer method gives the result in O(n) time complexity 
and since we are going to perform this method on n elements on nums array 
overall time complexity will become => O(n2)

*/

import (
	"slices"
)

func twoSum(sorted []int, target int) [][]int {
	startPointer := 0
	endPointer := len(sorted) - 1

	pairs := [][]int{}
	for startPointer < endPointer {
		if sorted[startPointer] + sorted[endPointer] > target {
			endPointer--
		} else if sorted[startPointer] + sorted[endPointer] < target {
			startPointer++
		} else if sorted[startPointer] + sorted[endPointer] == target {
			pairs = append(pairs, []int{sorted[startPointer], sorted[endPointer]})
			startPointer++
			endPointer--
		}
	} 
	return pairs
}

func sortThreeToString(a, b, c int) string {
	ns := []int{a, b, c}
	slices.Sort(ns)
	return fmt.Sprintf("%d|%d|%d", ns[0], ns[1], ns[2])
}

func threeSum(nums []int) [][]int {
	slices.Sort(nums)

	tripletsMap := map[string][]int{}
	for i, num := range nums {
		sorted := append([]int(nil), nums[:i]...)
		sorted = append(sorted, nums[i+1:]...)
		res := twoSum(sorted, -num)
		for _, p := range res {
			tripletsMap[sortThreeToString(p[0], p[1], num)] = []int{p[0], p[1], num}
		}
	}
	res := [][]int{}
	for _, v := range tripletsMap {
		res = append(res, v)
	}
	return res
}

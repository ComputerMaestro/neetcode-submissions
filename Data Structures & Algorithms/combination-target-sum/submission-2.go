/*
Brute force :
Try out all the combinations possible and check if the sum is equal to target or not . 
That will take O(2^n*n) time complexity 

we can also use bit manipulation for this for trying out all the combinations 
we can have numbers from 0 to 2^n - 1 , because tha is the range of combinations possible 
and each number has different bits and those bits represent whether the num is chosen or not 
if 1 then chosn 
if 0 then not chosen 

Backtracking:
Numbers all positive from 2 to 30 
that means if we track and the sum of tracked elements exceeds 6 those elements are not correct 

we keep adding nums to the sum and the added nums will be removed from the nums in the next recursive call and if we have
also the numbers availabel as choice for next recursive call will hold the values in trailing side of current selected value , because select previous values will created duplicate combinations

Time complexity will be O(2^n*n) because we have 2^n possible combinations and each combinations will need to added which will O(n) 
Space complexity will O(n) for maintaining the call stack 
*/

func combinationSum(nums []int, target int) [][]int {
    res := [][]int{}
    var rec func(nums []int, selectedNums []int, target, sum int)
    rec = func (nums, selectedNums []int, target, sum int) {
        if target == sum {
            combination := append([]int{}, selectedNums...)
            res = append(res, combination)
            return
        }
        if sum > target {
            return
        }
        for i, num := range nums {
            selectedNums = append(selectedNums, num)
            rec(nums[i:], selectedNums, target, sum+num)
            selectedNums = selectedNums[:len(selectedNums)-1]
        }
        return 
    }
    rec(nums, []int{}, target, 0)
    return res
}



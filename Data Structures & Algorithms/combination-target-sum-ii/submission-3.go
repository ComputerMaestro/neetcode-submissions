import (
	"slices"
)

func combinationSum2(candidates []int, target int) [][]int {
	slices.Sort(candidates)

	res := [][]int{}
	
	var rec func(int, int, int, []int) 
	rec = func(idx, target, sum int, selected []int) {
		if target == sum {
			sol := make([]int, len(selected))
			copy(sol, selected)
			res = append(res, sol)
			return
		}

		if idx >= len(candidates) || sum > target {
			return
		}

		prev := 0
		for i := idx; i < len(candidates); i++ {
			if prev == candidates[i] {
				continue
			} else {
				prev = candidates[i]
			}
			selected = append(selected, candidates[i])
			rec(i+1, target, sum + candidates[i], selected)
			selected = selected[:len(selected)-1]
		}

		return
	}
	rec(0, target, 0, []int{})
	return res
}

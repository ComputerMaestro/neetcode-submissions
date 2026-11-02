"""
Brute force solution
we can find all sub arrays sums and track the maximum 

time complexity will be O(n^2) 
space complexity will be O(1)

Greedy approach:
we will keep adding the values starting from left 
if the sum reaches less than zero or zero , than we again start from zero from the next element
as the overall negative or zero sum will always less the maximum possible sum array 

time complexity will be O(n)
space complexity will be O(1) few extra variables for track sum 
"""
import sys

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        largest = nums[0]
        sum = 0
        for num in nums:
            sum += num
            if sum < 0:
                sum = 0
                if largest < num:
                    largest = num
            elif sum > largest:
                largest = sum
        return largest
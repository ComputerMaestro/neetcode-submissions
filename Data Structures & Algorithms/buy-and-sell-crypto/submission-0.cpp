/*
Brute Force Solution: 
we loop over the array and for each value 
calculate the difference between all the values after current index 

return the max difference if positive, o if negative 

In this approach we will get O(n2) time complexity , because we will iterate n-1, n-2, n-3 ... 1 iteratins for each elements 
space complexity is O(1) as we are only using few extra variables


Sliding Window Solution: (Two pointer solution)
A profit can only happen when value is more than a previous value in the array 
and max project can happen if sell on the max possible value after the min value in a particular window 
Point is: min value will always come first and max value will come later 
that is why , we keep the window at the minimum value possible we saw and keep check it with upcomin values

We will make window in which we will know the minimum and maximum values 
window will start on the minimum value and we will keep track of the end of the window ( which will keep increasing) and the max value 
with every increase we check if profit < curAdded value - min value if yes profit will update
when we encounter a value which is less than current min value of window the window will reset at that point
this way we will always have the maximum possible profit at the end

Time complexity in this case : O(n) as will keep going forward to next value in each iteration 
Space complexity is again O(1) as we are only using few extra variables 
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        int profit = 0;
        int minId = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(profit < prices[i] - prices[minId]) {
                profit = prices[i] - prices[minId];
            }
            if(prices[minId] > prices[i]) {
                minId = i;
            }
        }
        return profit;
    }
};

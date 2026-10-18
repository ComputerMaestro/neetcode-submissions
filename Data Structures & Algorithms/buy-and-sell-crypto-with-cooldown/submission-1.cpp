/*
For every price in list on that day either we can sell or buy a coin 

backtrack 
we can keep tracking the day index when the stock was bought and each day has two options either sell or skip
if sold then skip next day and calculate max profit possible for remaining days
if skipp then go to next day 
if no bought index (-1) then buy a stock and continue wiht next days 
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> memo(prices.size()+1, vector<int>(prices.size()+1, -1));
        return dp(prices, memo, 0, -1);
    }

    int dp(vector<int>& prices, vector<vector<int>>& memo, int i, int buyIdx) {
        if (i >= prices.size()) {
            return 0;
        }
        int p = 0;
        if (buyIdx == -1) {
            p = max(dp(prices, memo, i+1, i), dp(prices, memo, i+1, -1));
        } else {
            if (memo[buyIdx][i] != -1) {
                return memo[buyIdx][i];
            }
            if (prices[i] - prices[buyIdx] > 0) {
                p = (prices[i] - prices[buyIdx]) + dp(prices, memo, i+2, -1);
            }
            p = max(p, dp(prices, memo, i+1, buyIdx));
            memo[buyIdx][i] = p;
        }
        return p;
    }
};

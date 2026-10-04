/*
Brute force solution:
loop over every element and check all leading elements whether any warmer day comes and store that 

in this since we might have to check for n-1, n-2, n-3 to 1 => O(n2) time complexity 
O(1) space complexity

Recursive solution:
For each element we will find the next warm day in remaing temperatures list 

in recursive function is cur element is greater than previous elements return this element and append count and keep return until the elements i greater once all returned or we encounter a value greater than this then start the recursion again for this element
base case will be : no furthur element so return 0 

STACK solution:
maintain a stack 
where we keeping push values until the top value is greater than current value 
once we find a value we keeping removing values from top and all keeping counting and inserting the count values in the result array for poping elements 
when ther is no more elements to be poped or the top element is greater than we push this cur element in the stack and continue with remaining temperatures 
at the end we pop all the elements and put zero for them in the result array 

also these elements which we are pushing are temperature index in the original array 
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> res;
        st.push(0);
        res.push_back(0);
        for(int i = 1; i < temperatures.size(); i++) {
            res.push_back(0);
            while(!st.empty() && temperatures[st.top()] < temperatures[i]) {
                int idx = st.top();
                st.pop();
                res[idx] = i - idx;
            }
            st.push(i);
        }
        while(!st.empty()) {
            res[st.top()] = 0;
            st.pop();
        }
        return res;
    }
};

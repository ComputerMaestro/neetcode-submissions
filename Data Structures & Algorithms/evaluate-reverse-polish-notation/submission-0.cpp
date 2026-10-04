
/*
Simple Operation First Approach
- Here, we will iteratively reduce the expression 
- in each iteration we will solve all the operands which have two preceding operands
- if not either the operation is to be performed after another operation preceding to it or it is an operation on the solutions of two operations. SO those will have ot solved in later iteration
- IN current after all simple operations are solved the operands and their operation can be removed from the array and replaced by their solution and this way we can solve whole expression 
But since we will have to traverse the array multiple times for n numbers in worst case will be O(n2) time complexity 
the space complexity is O(1) as only few variables will be needed


Using Stack
We will maintain a stack of operands
Parse the strings and append the operand at the top of the stack 
When encounter an operator pop two operands from the stack and perform the operation on these two operands and push the result on top of the stack and continue with next element on the array
*/

class Solution {
    vector<int> st;
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> st;
        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] == "+") {
                int b = st.back();
                st.pop_back();
                int a = st.back();
                st.pop_back();
                st.push_back(a+b);
            } else if(tokens[i] == "-") {
                int b = st.back();
                st.pop_back();
                int a = st.back();
                st.pop_back();
                st.push_back(a-b);
            } else if (tokens[i] == "*") {
                int b = st.back();
                st.pop_back();
                int a = st.back();
                st.pop_back();
                st.push_back(a*b);
            } else if(tokens[i] == "/") {
                int b = st.back();
                st.pop_back();
                int a = st.back();
                st.pop_back();
                st.push_back(a/b);
            } else {
                st.push_back(stoi(tokens[i]));
            }
        }
        return st.back();
    }
};

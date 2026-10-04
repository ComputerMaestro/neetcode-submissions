class MinStack {
    vector<int> minSt;
    vector<int> mainSt;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        mainSt.push_back(val);
        if(minSt.size() > 0) {
            minSt.push_back(min(minSt[minSt.size()-1], val));
        } else {
            minSt.push_back(val);
        }
    }
    
    void pop() {
        mainSt.pop_back();
        minSt.pop_back();
    }
    
    int top() {
        return mainSt[mainSt.size()-1];
    }
    
    int getMin() {
        return minSt[minSt.size()-1];
    }
};

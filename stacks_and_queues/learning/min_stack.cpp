// Leetcode 155. Min Stack

class MinStack {
private:
    stack<int> s;
    stack<int> min;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if (min.empty()) min.push(val);
        else if (min.top()>=val) min.push(val); 
    }
    
    void pop() {
        if (min.top()==s.top()){
            min.pop();
            s.pop();
            return;
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min.top();
    }
};
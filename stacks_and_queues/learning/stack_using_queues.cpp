// Leetcode 255. Implement Stack using queues
// using 2 queues -->

class MyStack {
private:
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {

    }
    
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    
    int pop() {
        int x = q1.front();
        q1.pop();
        return x;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};


//-----------------------------------------------------------------------------------------------------
// using 1 queue

class MyStack {
private:
    queue<int> q;
public:
    MyStack() {

    }
    
    void push(int x) {
        q.push(x);
        for (int i=0;i<q.size()-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
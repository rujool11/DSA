#include <bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int>& s, int x){
    // If stack is empty or x is greater than top element
    if (s.empty() || x > s.top()){
        s.push(x);
        return;
    }

    // If top is greater than x, pop the top and recur
    int temp = s.top();
    s.pop();
    sortedInsert(s, x);

    // Push back the top element after inserting x
    s.push(temp);
}

void sortStack(stack<int>& s){
    // Base case: if stack is empty, return
    if (s.empty()) return;

    // Pop the top element
    int x = s.top();
    s.pop();

    // Sort the remaining stack
    sortStack(s);

    // Insert the popped element back in the sorted stack
    sortedInsert(s, x);
}

void printStack(stack<int> s) {
    // Print stack elements
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main(){
    stack<int> s;
    s.push(89);
    s.push(98);
    s.push(12);
    s.push(78);

    cout << "Original Stack: ";
    printStack(s);

    sortStack(s);

    cout << "Sorted Stack: ";
    printStack(s);

    return 0;
}

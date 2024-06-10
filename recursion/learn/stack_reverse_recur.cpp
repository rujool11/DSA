#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int>& s, int x) {
    if (s.empty()) {
        s.push(x);
        return;
    }

    int temp = s.top();
    s.pop();
    insertAtBottom(s, x);

    s.push(temp);
}

void reverseStack(stack<int>& s) {
    if (s.empty()) return;

    int x = s.top();
    s.pop();

    reverseStack(s);

    insertAtBottom(s, x);
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

    reverseStack(s);

    cout << "Reversed Stack: ";
    printStack(s);

    return 0;
}

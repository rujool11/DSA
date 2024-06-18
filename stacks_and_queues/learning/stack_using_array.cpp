// Stack -> lifo
#include <iostream>
using namespace std;

class Stack {
private:
    int size; 
    int *arr; 
    int top;

public:
    Stack(int s = 20) {
        size = s;
        arr = new int[size];
        top = -1;
    }

    void push(int x) { 
        arr[++top] = x;
    }

    int pop() {
        return arr[top--];
    }

    int getTop() { 
        return arr[top];
    }

    void print() { // Print method to print all elements of stack
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

};


int main() {


    Stack s;
    s.push(4);
    s.push(5);
    s.push(6);
    s.print();
    cout<<s.pop()<<endl;
    s.print();
    return 0;
}

#include<iostream>
using namespace std;
#define SIZE 100
template <class T>
class Stack {
private:
    T stack[SIZE];
    int top;

public:
    Stack() { top = -1; }

    void PUSH(T item) {
        if (top == SIZE - 1) {
            cout << "Stack Overflow!\n";
        } else {
            stack[++top] = item;
        }
    }

    T POP() {
        if (top == -1) {
            return '\0';
        } else {
            return stack[top--];
        }
    }

    T PEEK() {
        if (top == -1)
            return '\0';
        else
            return stack[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    void DISPLAY() {
        if (top == -1) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

int main(){

    Stack <int> intStack;
    intStack.PUSH(10);
    intStack.PUSH(20);
    intStack.DISPLAY();
    return 0;
}
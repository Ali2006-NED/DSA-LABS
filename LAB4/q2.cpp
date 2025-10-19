#include<iostream>
using namespace std;

#define SIZE 5

class Stack {
private:
    int stack[SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }
    int peek(){
        if (top == -1){
            cout << "Stack is empty.\n";
            return -1; // Indicate stack is empty
        } else {
            return stack[top];
        }
    }
    void PUSH() {  
        int item;
        if (top == SIZE - 1) {
            cout << "Stack Overflow!\n";
        } else {
            cout << "Enter item to push: ";
            cin >> item;
            top++;
            stack[top] = item;
            cout << "Item " << item << " inserted successfully.\n";
        }
    }
};

int main(){
    Stack s;
    s.PUSH();
    s.PUSH();
    cout << "Top element is: " << s.peek() << endl;
    return 0;

}
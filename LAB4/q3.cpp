#include <iostream>
#include <string>
using namespace std;

#define SIZE 50

// Template Stack class
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
            cout << "Stack Underflow!\n";
            return -1;
        } else {
            return stack[top--];
        }
    }

    T PEEK() {
        if (top == -1) {
            return -1;
        } else {
            return stack[top];
        }
    }

    bool isEmpty() {
        return top == -1;
    }
};

// Function to return precedence of operators
int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

// Function to check if character is operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to convert Infix to Postfix
string infixToPostfix(string infix) {
    Stack<char> s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        // Skip spaces
        if (ch == ' ')
            continue;

        // If operand, add to postfix
        if (isalnum(ch)) {
            postfix += ch;
        }

        // If '(', push to stack
        else if (ch == '(') {
            s.PUSH(ch);
        }

        // If ')', pop until '('
        else if (ch == ')') {
            while (!s.isEmpty() && s.PEEK() != '(') {
                postfix += s.POP();
            }
            s.POP(); // Remove '('
        }

        // If operator
        else if (isOperator(ch)) {
            while (!s.isEmpty() && precedence(s.PEEK()) >= precedence(ch)) {
                postfix += s.POP();
            }
            s.PUSH(ch);
        }
    }

    // Pop remaining operators
    while (!s.isEmpty()) {
        postfix += s.POP();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);

    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}

#include <iostream>
#include <string>
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
};


bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}


bool checkBalancedParentheses(string expr) {
    Stack<char> s;

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            s.PUSH(ch);
        } 
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty() || !isMatchingPair(s.POP(), ch)) {
                return false; 
            }
        }
    }

    
    return s.isEmpty();
}

int main() {
    string expression;

    cout << "Enter an expression: ";
    getline(cin, expression);

    if (checkBalancedParentheses(expression))
        cout << "Parentheses are balanced" << endl;
    else
        cout << "Parentheses are not balanced" << endl;

    return 0;
}

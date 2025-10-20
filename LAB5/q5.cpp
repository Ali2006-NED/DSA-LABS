#include <iostream>
#include <string>
using namespace std;


template <typename T>
class LinkedListStack {
private:
    struct Node {
        T data;
        Node* next;
    };
    Node* top;

public:
    LinkedListStack() { top = nullptr; }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(const T& val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = top;
        top = newNode;
    }

    T pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return T(); // return default value of type T
        }
        T val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }

    T peek() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return T();
        }
        return top->data;
    }
};

// Function to check matching pairs of parentheses
bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

// Function to check if parentheses are balanced
bool isBalanced(const string& expr) {
    LinkedListStack<char> stack;

    for (char c : expr) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push(c);
        } 
        else if (c == ')' || c == ']' || c == '}') {
            if (stack.isEmpty()) return false;

            char topChar = stack.pop();
            if (!isMatchingPair(topChar, c))
                return false;
        }
    }

    return stack.isEmpty();
}


int main() {
    string expr;
    cout << "Enter expression: ";
    cin >> expr;

    if (isBalanced(expr))
        cout << "Parentheses are balanced.\n";
    else
        cout << "Parentheses are not balanced.\n";

    return 0;
}

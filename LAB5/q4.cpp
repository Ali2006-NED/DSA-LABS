#include <iostream>
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
    
    LinkedListStack() {
        top = nullptr;
    }

    
    bool isEmpty() {
        return top == nullptr;
    }

    
    void push() {
        T val;
        cout << "Enter value to push: ";
        cin >> val;
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = top;
        top = newNode;
        cout << val << " pushed into stack.\n";
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
            return T();  
        }
        T val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }

    
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        Node* temp = top;
        cout << "Stack elements (top to bottom): ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Reverse the stack using another stack
    void reverseStack(LinkedListStack<T>& other) {
        while (!isEmpty()) {
            T val = pop();
            other.push(val);
        }
        cout << "Stack reversed successfully!\n";
    }
};

// Demonstration
int main() {
    LinkedListStack<int> stack1;
    LinkedListStack<int> stack2;

    cout << "--- Pushing Elements ---\n";
    stack1.push();
    stack1.push();
    stack1.push();

    cout << "\nBefore Reversal: ";
    stack1.display();

    // Reverse stack1 into stack2
    stack1.reverseStack(stack2);

    cout << "\nAfter Reversal: ";
    stack2.display();

    return 0;
}

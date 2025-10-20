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

    
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return;
        }

        Node* temp = top;
        cout << top->data << " popped from stack.\n";
        top = top->next;
        delete temp;
    }

    
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "Stack elements: ";
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


int main() {
    LinkedListStack<int> stack;

    
    stack.pop();        
    stack.display();    
    
    return 0;
}
